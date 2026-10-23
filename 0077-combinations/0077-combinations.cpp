class Solution {

public:
    vector<vector<int>> result;
    void solve(int start, int n, int k, vector<int>& curr) {
        if (curr.size() == k) {
            result.push_back(curr);
            return;
        }

        for (int i = start; i <= n - (k - curr.size()) + 1; i++) {
            curr.push_back(i);
            solve(i + 1, n, k, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> curr;
        solve(1, n, k, curr);
        return result;
    }
};