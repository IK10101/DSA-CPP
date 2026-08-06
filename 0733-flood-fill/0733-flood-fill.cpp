class Solution {
   private:
    void dfs(int row, int col, vector<vector<int>> &ans,
             vector<vector<int>> &image, int newColor, int dr[], int dc[],
             int iniColor) {
        int n = image.size();
        int m = image[0].size();
        ans[row][col] = newColor;
        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                image[nrow][ncol] == iniColor && ans[nrow][ncol] != newColor) {
                dfs(nrow, ncol, ans, image, newColor, dr, dc, iniColor);
            }
        }
    }

   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int newColor) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        dfs(sr, sc, ans, image, newColor, dr, dc, iniColor);
        return ans;
    }
};
