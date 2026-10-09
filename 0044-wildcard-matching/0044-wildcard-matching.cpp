class Solution {

public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        prev[0] = true;
        for (int i = 1; i <= n; i++) {
            curr[0] = false;
        }
        for (int j = 1; j <= m; j++) {
            bool flag = true;
            for (int x = 0; x < j; x++) {
                if (p[x] != '*') {
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                    curr[j] = prev[j - 1];
                }

                else if (p[j - 1] == '*') {
                    curr[j] = prev[j] || curr[j - 1];
                } else {
                    curr[j] = false;
                }
            }
            prev = curr;
        }
        return prev[m];
    }
};