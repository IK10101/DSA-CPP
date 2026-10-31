class Solution {
private:
    bool isValid(int i, int j, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        return (i < m && i >= 0 && j < n && j >= 0);
    }
    int solve(int i, int j, int prev, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp) {
        int m = grid.size();
        int n = grid[0].size();
        int pos1 = 0;
        int pos2 = 0;
        if (!isValid(i, j, grid))
            return 0;
        if (dp[i][j][prev] != -1)
            return dp[i][j][prev];
        if (i == m - 1 && j == n - 1)
            return 1;

        if (grid[i][j] == 0) {
            pos1 =
                (solve(i + 1, j, 0, grid, dp) + solve(i, j + 1, 1, grid, dp)) %
                MOD;
        } else if (grid[i][j] == 1) {
            if (prev == 0) {
                pos2 = solve(i, j + 1, 1, grid, dp);
            } else if (prev == 1) {
                pos2 = solve(i + 1, j, 0, grid, dp);
            } else {
                pos2 = (solve(i + 1, j, 0, grid, dp) +
                        solve(i, j + 1, 1, grid, dp)) %
                       MOD;
            }
        }
        return dp[i][j][prev] = (pos1 + pos2) % MOD;
    }

public:
    const int MOD = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(3, -1)));
        return solve(0, 0, 2, grid, dp) % MOD;
    }
};