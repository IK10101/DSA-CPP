class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int len = 1; len <= n; len++) {

            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                if (len == 1)
                    dp[i][j] = true;
                else if (len == 2)
                    dp[i][j] = s[i] == s[j];
                else
                    dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};