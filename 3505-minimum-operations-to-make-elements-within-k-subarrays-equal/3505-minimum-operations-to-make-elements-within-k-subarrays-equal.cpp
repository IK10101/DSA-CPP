class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);
        multiset<int> lower_half, larger_half;
        long long sumLo = 0, sumHi = 0;

        auto rebalance = [&]() {
            size_t target = (lower_half.size() + larger_half.size() + 1) / 2;
            while (lower_half.size() > target) {
                auto it = prev(lower_half.end());
                sumLo -= *it;
                sumHi += *it;
                larger_half.insert(*it);
                lower_half.erase(it);
            }
            while (lower_half.size() < target) {
                auto it = larger_half.begin();
                sumHi -= *it;
                sumLo += *it;
                lower_half.insert(*it);
                larger_half.erase(it);
            }
        };

        auto add = [&](int v) {
            if (lower_half.empty() || v <= *lower_half.rbegin()) {
                lower_half.insert(v);
                sumLo += v;
            } else {
                larger_half.insert(v);
                sumHi += v;
            }
            rebalance();
        };

        auto remove = [&](int v) {
            if (v <= *lower_half.rbegin()) {
                lower_half.erase(lower_half.find(v));
                sumLo -= v;
            } else {
                larger_half.erase(larger_half.find(v));
                sumHi -= v;
            }
            rebalance();
        };

        for (int i = 0; i < n; i++) {
            if (i >= x)
                remove(nums[i - x]);
            add(nums[i]);
            if (i >= x - 1) {
                long long med = *lower_half.rbegin();
                cost[i - x + 1] = med * (long long)lower_half.size() - sumLo +
                                  sumHi - med * (long long)larger_half.size();
            }
        }

        const long long INF = 1e18;
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (i >= x && dp[i - x][j - 1] != INF)
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + cost[i - x]);
            }
        }
        return dp[n][k];
    }
};