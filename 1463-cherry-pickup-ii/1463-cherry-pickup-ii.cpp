class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, 0)));

        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2) {
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                } else {
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
                }
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = INT_MIN;

                    for (int di = -1; di <= 1; di++) {
                        for (int dj = -1; dj <= 1; dj++) {
                            int newJ1 = j1 + di;
                            int newJ2 = j2 + dj;

                            if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 &&
                                newJ2 < m) {
                                int ans;

                                if (j1 == j2) {
                                    ans =
                                        grid[i][j1] + dp[i + 1][newJ1][newJ2];
                                } else {
                                    ans = grid[i][j1] + grid[i][j2] +
                                          dp[i + 1][newJ1][newJ2];
                                }

                                maxi = max(maxi, ans);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][m - 1];
    }
};