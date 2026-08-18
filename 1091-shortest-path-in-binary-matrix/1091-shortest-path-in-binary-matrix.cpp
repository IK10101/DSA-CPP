class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return -1;

        if (n == 1)
            return 1;

        queue<pair<int, pair<int, int>>> q;

        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        dist[0][0] = 1;
        q.push({1, {0, 0}});

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (!q.empty()) {

            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            for (int i = 0; i < 8; i++) {

                int newrow = row + dr[i];
                int newcol = col + dc[i];

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < n &&
                    grid[newrow][newcol] == 0 &&
                    dis + 1 < dist[newrow][newcol]) {

                    dist[newrow][newcol] = dis + 1;

                    if (newrow == n - 1 && newcol == n - 1)
                        return dis + 1;

                    q.push({dis + 1, {newrow, newcol}});
                }
            }
        }

        return -1;
    }
};