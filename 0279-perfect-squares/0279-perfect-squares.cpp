class Solution {
    int f(int n, vector<int>& dp) {
        if (n == 0)
            return 0;
        if (dp[n] != -1)
            return dp[n];
        int ans = n;

        for (int j = 1; j * j <= n; j++) {
            ans = min(ans, 1 + f(n - j * j, dp));
        }

        return dp[n] = ans;
    }

public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return f(n, dp);
    }
};