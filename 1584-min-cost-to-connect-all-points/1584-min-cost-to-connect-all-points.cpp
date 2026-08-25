class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        int sum = 0;
        pq.push({0, 0});
        vector<int> vis(V, 0);
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int wt = it.first;
            if (vis[node] == 1)
                continue;
            vis[node] = 1;
            sum += wt;
            for (int i = 0; i < V; i++) {
                if (!vis[i]) {
                    int edgW = abs(points[node][0] - points[i][0]) +
                               abs(points[node][1] - points[i][1]);
                    pq.push({edgW, i});
                }
            }
        }
        return sum;
    }
};