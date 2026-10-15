class Solution {

public:
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int len = 2; len < m; len++) {
            for (int i = 0; i + len < m; i++) {
                int j = i + len;
                int mini = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    int cost = (cuts[j] - cuts[i]) + dp[i][k] + dp[k][j];
                    mini = min(cost, mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[0][m - 1];
    }
};