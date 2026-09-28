class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<unsigned long long>> dp(
            n, vector<unsigned long long>(amount + 1, -1));
        for (int amt = 0; amt <= amount; amt++) {
            dp[0][amt] = (amt % coins[0] == 0);
        }
        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                unsigned long long notTake = dp[ind - 1][amt];
                unsigned long long take = 0;
                if (coins[ind] <= amt)
                    take = dp[ind][amt - coins[ind]];
                dp[ind][amt] = (take + notTake);
            }
        }
        return dp[n - 1][amount];
    }
};