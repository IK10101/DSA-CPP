class Solution {
private:
    bool ispalindrome(int left, int right, string& s) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }

        return true;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int mini = INT_MAX;
            for (int j = i; j < n; j++) {
                if (ispalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    mini = min(cost, mini);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }
};