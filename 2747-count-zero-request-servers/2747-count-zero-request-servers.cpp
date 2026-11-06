class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        int m = logs.size();
        int a = queries.size();
        vector<pair<int, int>> q;
        for (int i = 0; i < a; i++) {
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());

        sort(logs.begin(), logs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int left = 0;
        int right = 0;
        int active = 0;
        vector<int> freq(n + 1, 0);
        vector<int> ans(a);
        for (int i = 0; i < a; i++) {
            int qTime = q[i].first;
            int L = qTime - x;
            int R = qTime;

            while (right < m && logs[right][1] <= R) {
                int id = logs[right][0];
                if (freq[id] == 0)
                    active++;
                freq[id]++;
                right++;
            }

            while (left < right && logs[left][1] < L) {
                int id = logs[left][0];
                freq[id]--;
                if (freq[id] == 0) {
                    active--;
                }
                left++;
            }
            ans[q[i].second] = n - active;
        }
        return ans;
    }
};