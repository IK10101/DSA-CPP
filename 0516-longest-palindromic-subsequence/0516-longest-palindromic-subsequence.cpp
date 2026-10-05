class Solution {

public:
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int n = s.size();
        vector<int> prev(n + 1, 0);
        vector<int> curr(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == rev[j]) {
                    curr[j] = 1 + prev[j + 1];
                } else {
                    curr[j] = max(prev[j], curr[j + 1]);
                }
            }
            prev = curr;
        }
        return prev[0];
    }
};