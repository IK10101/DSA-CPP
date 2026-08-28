class DisjointSet {
public:
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    bool find(int u, int v) { return (findUPar(u) == findUPar(v)); }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
private:
    bool isValid(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step-1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNo = row * n + col;
                        int AdjnodeNo = nrow * n + ncol;
                        ds.unionBySize(nodeNo, AdjnodeNo);
                    }
                }
            }
        }
        int ans = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                set<int> components;
                if (grid[row][col] == 1)
                    continue;
                int dr[] = {-1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int nrow = row + dr[ind];
                    int ncol = col + dc[ind];
                    if (isValid(nrow, ncol, n) && grid[nrow][ncol] == 1) {
                        int nodeNum = nrow * n + ncol;
                        components.insert(ds.findUPar(nodeNum));
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                ans = max(ans, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            ans = max(ans,ds.size[ds.findUPar(cellNo)]);
        }

        return ans;
    }
};