class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& vis,
                  vector<int>& pathVis, vector<int>& check) {
        int V = graph.size();
        vis[node] = 1;
        pathVis[node] = 1;
        check[node] = 0;

        for (auto it : graph[node]) {
            if (!vis[it]) {
                if (dfsCheck(it, graph, vis, pathVis, check) == true) {
                    check[node] = 0;
                    return true;
                }

            } else if (pathVis[it]) {
                check[node] = 0;
                return true;
            }
        }
        check[node] = 1;
        pathVis[node] = 0;
        return false;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int V = graph.size();
        vector<int> vis(V);

        vector<int> pathVis(V);

        vector<int> check(V);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfsCheck(i, graph, vis, pathVis, check);
            }
        }
        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (check[i] == 1)
                ans.push_back(i);
        }
        return ans;
    }
};