class Solution {
private:
    bool checkPossible(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1)
            return false;
        int i = 0;
        int j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++;
            }
        }
        if (i == s1.size() && j == s2.size())
            return true;
        return false;
    }

public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(),
             [](string& a, string& b) { return a.size() < b.size(); });
        vector<int> dp(n, 1);

        int maxi = 0;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {
                if (checkPossible(words[i], words[j]) && 1 + dp[j] > dp[i]) {
                    dp[i] = 1 + dp[j];
                }
            }
            if (dp[i] > maxi)
                maxi = dp[i];
        }

        return maxi;
    }
};