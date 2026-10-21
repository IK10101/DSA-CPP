class Solution {
private:
    int f(int n, vector<int>& dp) {
        if (n == 0 || n == 1)
            dp[n] = 1;
        if (dp[n] != -1)
            return dp[n];

        dp[n] = 0;
        for (int i = 1; i <= n; i++) {
            dp[n] += f(i - 1, dp) * f(n - i, dp);
        }

        return dp[n];
    }

public:
    int numTrees(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};