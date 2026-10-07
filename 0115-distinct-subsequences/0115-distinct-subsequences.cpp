class Solution {
    const int MOD = 1e9 + 7;

public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        prev[0] = 1;
        for (int i = 0; i <= n; i++) {
            curr[0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {

                if (s[i - 1] == t[j - 1]) {
                    curr[j] = (prev[j - 1] + prev[j]) % MOD;
                } else {
                    curr[j] = prev[j];
                }
            }
            prev = curr;
        }

        return prev[m] % MOD;
    }
};