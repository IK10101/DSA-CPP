class Solution {
private:
    bool ispalindrome(int left, int right, string& s) {
        while (left < right) {
            if (s[left++] != s[right--])
                return false;
        }

        return true;
    }
    int f(int i, string& s, vector<int>& dp) {
        int n = s.size();
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int mini = INT_MAX;
        for (int j = i; j < n; j++) {
            if (ispalindrome(i, j, s)) {
                int cost = 1 + f(j + 1, s, dp);
                mini = min(cost, mini);
            }
        }
        return dp[i] = mini;
    }

public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n, -1);
        return f(0, s, dp) - 1;
    }
};