class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, int color[]) {
        int V = graph.size();
        queue<int> q;
        q.push(start);
        color[start] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : graph[node]) {
                if (color[it] == -1) {
                    color[it] = !color[node];
                    q.push(it);
                } else if (color[it] == color[node]) {
                    return false;
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for (int i = 0; i < V; i++)
            color[i] = -1;
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!check(i, graph, color))
                    return false;
            }
        }
        return true;
    }
};