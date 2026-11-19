class Solution {
private:
    int solve(int i, vector<int>& rewardValues, vector<vector<int>>& dp,
              int x) {
        int n = rewardValues.size();
        if (i == n)
            return 0;
        if (dp[i][x] != -1)
            return dp[i][x];
        int reward1 = 0;
        int reward2 = solve(i + 1, rewardValues, dp, x);
        if (x < rewardValues[i]) {
            reward1 = rewardValues[i] +
                      solve(i + 1, rewardValues, dp, x + rewardValues[i]);
        }
        return dp[i][x] = max(reward1, reward2);
    }

public:
    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(), rewardValues.end());
        int n = rewardValues.size();
        int x = 0;
        vector<vector<int>> dp(n + 1, vector<int>(4001, -1));
        return solve(0, rewardValues, dp, x);
    }
};