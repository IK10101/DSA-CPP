class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1), hash(n);
        int maxi = 0;
        int lastind = 0;
        for (int i = 0; i < n; i++) {
            hash[i] = i;
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < 1 + dp[j]) {
                    dp[i] = 1 + dp[j];
                    hash[i] = j;
                }
            }
            if (maxi < dp[i]) {
                maxi = dp[i];
                lastind = i;
            }
        }
        vector<int> ans;
        int i = lastind;
        while (hash[i] != i) {
            ans.push_back(nums[i]);
            i = hash[i];
        }
        ans.push_back(nums[i]);
        return ans;
    }
};