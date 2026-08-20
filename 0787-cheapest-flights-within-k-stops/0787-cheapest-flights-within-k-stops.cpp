class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<pair<int,int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        q.push({0, {src, 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int costs = it.second.second;

            if (stops > k)
                continue;

            for (auto itr : adj[node]) {
                int adjNode = itr.first;
                int edgW = itr.second;
                if (costs + edgW < dist[adjNode] && stops <= k) {
                    dist[adjNode] = costs + edgW;
                    q.push({stops + 1, {adjNode, costs + edgW}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];
    }
};