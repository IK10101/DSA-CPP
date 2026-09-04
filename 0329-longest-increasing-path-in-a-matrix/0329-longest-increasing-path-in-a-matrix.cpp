class Solution {

public:
    int m, n;
    bool isValid(int i, int j) { return (i >= 0 && i < m && j >= 0 && j < n); }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        m = matrix.size();
        n = matrix[0].size();
        vector<vector<int>> indegree(m, vector<int>(n, 0));
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                for (int ind = 0; ind < 4; ind++) {
                    int nr = r + dr[ind];
                    int nc = c + dc[ind];

                    if (isValid(nr, nc) && matrix[nr][nc] < matrix[r][c]) {
                        indegree[r][c]++;
                    }
                }
            }
        }
        queue<pair<int, int>> q;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (indegree[r][c] == 0) {
                    q.push({r, c});
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {
            int size = q.size();
            ans++;

            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                for (int ind = 0; ind < 4; ind++) {
                    int nr = r + dr[ind];
                    int nc = c + dc[ind];

                    if (isValid(nr, nc) && matrix[nr][nc] > matrix[r][c]) {
                        indegree[nr][nc]--;

                        if (indegree[nr][nc] == 0) {
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
        return ans;
    }
};