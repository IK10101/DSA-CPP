class Solution {
public:
    vector<int> ans, path[26];

    void dfs(int u, vector<vector<int>>& adj, string& s, vector<int>& par) {
        int c = s[u] - 'a';

        if (!path[c].empty())
            par[u] = path[c].back();

        path[c].push_back(u);

        for (int v : adj[u])
            dfs(v, adj, s, par);

        path[c].pop_back();
    }

    int calc(int u, vector<vector<int>>& adj) {
        int sz = 1;
        for (int v : adj[u])
            sz += calc(v, adj);

        return ans[u] = sz;
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n), tree(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        dfs(0, adj, s, parent);

        for (int i = 1; i < n; i++)
            tree[parent[i]].push_back(i);

        ans.resize(n);
        calc(0, tree);

        return ans;
    }
};