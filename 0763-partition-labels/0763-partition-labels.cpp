class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> first(26, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            int ind = s[i] - 'a';

            if (first[ind] == -1) {
                first[ind] = i;
            }
            last[ind] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < n; i++) {
            int ind = s[i] - 'a';

            end = max(end, last[ind]);

            if (i == end) {
                ans.push_back(end - start + 1);
                start = i + 1;
            }
        }
        return ans;
    }
};