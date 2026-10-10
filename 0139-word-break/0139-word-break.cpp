class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        set<string> word(wordDict.begin(), wordDict.end());

        vector<bool> dp(n + 1);
        dp[0] = true;
        int maxlen = 0;
        for (auto i : wordDict) {
            maxlen = max(maxlen, (int)i.size());
        }
        for (int i = 0; i < n; i++) {
            if (dp[i] == false)
                continue;
            for (int len = 1; len <= maxlen && i + len <= n; len++) {
                if (word.count(s.substr(i, len)))
                    dp[i + len] = true;
            }
        }
        return dp[n];
    }
};