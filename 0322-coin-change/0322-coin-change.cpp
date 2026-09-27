class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) {
                dp[0][T] = T / coins[0];
            } else
                dp[0][T] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notPick = 0 + dp[ind - 1][tar];
                int pick = INT_MAX;
                if (coins[ind] <= tar)
                    pick = 1 + dp[ind][tar - coins[ind]];
                dp[ind][tar] = min(pick, notPick);
            }
        }
        int ans = dp[n - 1][amount];
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};