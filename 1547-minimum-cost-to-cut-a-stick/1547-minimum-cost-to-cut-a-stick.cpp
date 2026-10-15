class Solution {
private:
    int f(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (j - i == 1)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int mini = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost =
                (cuts[j] - cuts[i]) + f(i, k, cuts, dp) + f(k, j, cuts, dp);
            mini = min(cost, mini);
        }
        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
        return f(0, m - 1, cuts, dp);
    }
};