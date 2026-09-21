class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int v = num % k;
            vector<long long> next(k, 0);

            next[v]++;

            for (int r = 0; r < k; ++r) {
                int nr = (1LL * r * v) % k;
                next[nr] += dp[r];
            }

            for (int r = 0; r < k; ++r) {
                result[r] += next[r];
            }

            dp.swap(next);
        }

        return result;
    }
};