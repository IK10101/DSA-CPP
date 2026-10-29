class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
             [](auto& a, auto& b) { return a[1] < b[1]; });

        int cnt = 0;
        int lastend = INT_MIN;
        for (auto p : pairs) {
            if (p[0] > lastend) {
                cnt++;
                lastend = p[1];
            }
        }
        return cnt;
    }
};