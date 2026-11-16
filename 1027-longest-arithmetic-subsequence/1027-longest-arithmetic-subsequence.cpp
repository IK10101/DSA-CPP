class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[j] - nums[i];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};