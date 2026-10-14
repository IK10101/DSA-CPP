class Solution {
private:
    int f(int i,vector<int>& arr, int k,vector<int> &dp){
        int n = arr.size();
        if (i == n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int limit = min(n - i, k);
        int currmaxi = INT_MIN;
        int maxi = INT_MIN;
        for (int j = i; j < i + limit; j++) {
            currmaxi = max(currmaxi, arr[j]);
            int sum = (j - i + 1) * currmaxi + f(j + 1,arr,k,dp);
            maxi = max(maxi, sum);
        }
        return dp[i] = maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, arr, k, dp);
    }
};