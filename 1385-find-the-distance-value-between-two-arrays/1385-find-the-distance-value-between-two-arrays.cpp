class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        int m = arr1.size();
        int n = arr2.size();
        for (int i = 0; i < m; i++) {
            bool fl = false;
            for (int j = 0; j < n; j++) {
                if (abs(arr1[i] - arr2[j]) <= d) {
                    fl = true;
                    break;
                }
            }
            if (!fl) {
                ans++;
            }
        }
        return ans;
    }
};