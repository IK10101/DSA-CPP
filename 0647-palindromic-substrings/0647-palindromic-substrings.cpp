class Solution {
private:
    int solve(int i, int j, string& s, vector<vector<int>>& dp) {
        if (i == j)
            dp[i][j] = 1;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (j - i == 1)
            return dp[i][j] = (s[i] == s[j]);
        dp[i][j] = (s[i] == s[j]) && solve(i + 1, j - 1, s, dp);
        return dp[i][j];
    }

public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cnt += solve(i, j, s, dp);
            }
        }
        return cnt;
    }
};