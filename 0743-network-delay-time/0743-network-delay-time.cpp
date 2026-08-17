class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<vector<int>>> adj(n + 1);
        for (auto& e : times) {
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            adj[u].push_back({v, wt});
        }

        set<pair<int, int>> st;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;
        st.insert({0, k});

        while (!st.empty()) {
            auto it = *(st.begin());
            int currdist = it.first;
            int node = it.second;
            st.erase(it);
            for (auto it : adj[node]) {
                int adjNode = it[0];
                int edgeWeight = it[1];

                if (currdist + edgeWeight < dist[adjNode]) {
                    if (dist[adjNode] != 1e9)
                        st.erase({dist[adjNode], adjNode});
                    dist[adjNode] = currdist + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;
            ans = max(ans, dist[i]);
        }

        return ans;
    }
};