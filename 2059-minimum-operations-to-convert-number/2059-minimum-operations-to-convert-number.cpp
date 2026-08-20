class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        if (start == goal)
            return 0;
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(1001, 1e9);
        dist[start] = 0;
        while (!q.empty()) {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for (auto it : nums) {
                int num1 = node + it;
                int num2 = node - it;
                int num3 = node ^ it;

                int next[] = {num1, num2, num3};

                for (auto i : next) {
                    if (i == goal)
                        return steps + 1;

                    if (i < 0 || i > 1000)
                        continue;

                    if (steps + 1 < dist[i]) {
                        dist[i] = steps + 1;
                        q.push({i, steps + 1});
                    }
                }
            }
        }
        return -1;
    }
};