class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();
        set<int> avail;
        for (int i = 0; i < k; i++) {
            avail.insert(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> cnt(k, 0);
        for (int i = 0; i < n; i++) {
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                avail.insert(pq.top().second);
                pq.pop();
            }
            if (avail.empty()) {
                continue;
            }
            int a = i % k;
            auto it = avail.lower_bound(a);
            if (it == avail.end())
                it = avail.begin();
            int ind = *it;
            avail.erase(it);
            cnt[ind]++;
            pq.push({arrival[i] + load[i], ind});
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++) {
            if (cnt[i] == mx) {
                res.push_back(i);
            }
        }
        return res;
    }
};