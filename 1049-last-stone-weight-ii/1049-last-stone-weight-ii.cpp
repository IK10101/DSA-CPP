class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int totsum = 0;
        for (int i = 0; i < n; i++) {
            totsum += stones[i];
        }

        int target = totsum / 2;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (stones[0] <= target) {
            dp[0][stones[0]] = true;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int j = 1; j <= target; j++) {
                bool notTaken = dp[ind - 1][j];
                bool taken = false;
                if (stones[ind] <= j) {
                    taken = dp[ind - 1][j - stones[ind]];
                }
                dp[ind][j] = notTaken || taken;
            }
        }

        int mini = 1e9;

        for (int s1 = 0; s1 <= totsum / 2; s1++) {
            if (dp[n - 1][s1] == true) {
                mini = min(mini, abs(s1 - (totsum - s1)));
            }
        }
        return mini;
    }
};