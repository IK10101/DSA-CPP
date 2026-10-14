class Solution {

public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            int limit = min(n - i, k);
            int currmaxi = INT_MIN;
            int maxi = INT_MIN;
            for (int j = i; j < i + limit; j++) {
                currmaxi = max(currmaxi, arr[j]);
                int sum = (j - i + 1) * currmaxi + dp[j + 1];
                maxi = max(maxi, sum);
            }
            dp[i] = maxi;
        }
        return dp[0];
    }
};