class Solution {
public:
    vector<int> parent, size;
    int findPar(int node) {
        if (parent[node] == node) {
            return node;
        }
        return parent[node] = findPar(parent[node]);
    }
    void unionbysize(int u, int v) {
        int ulp_u = findPar(u);
        int ulp_v = findPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            if (findPar(u) == findPar(v)) {
                return {u, v};
            }
            unionbysize(u, v);
        }
        return {};
    }
};