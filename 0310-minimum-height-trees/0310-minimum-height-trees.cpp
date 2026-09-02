class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1)
            return {0};
        vector<vector<int>> adj(n);
        vector<int> deg(n, 0);

        for (auto e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 1)
                q.push(i);
        }

        while (n > 2) {
            int size = q.size();
            n -= size;

            while (size--) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    deg[v]--;
                    if (deg[v] == 1)
                        q.push(v);
                }
            }
        }
        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};