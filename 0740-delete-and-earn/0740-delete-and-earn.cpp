class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> pts(maxi + 1, 0);
        vector<int> dp(maxi + 3, 0);
        for (int x : nums) {
            pts[x] += x;
        }
        for (int i = maxi; i >= 0; i--) {
            int take = pts[i] + dp[i + 2];
            int notTake = 0 + dp[i + 1];
            dp[i] = max(take, notTake);
        }
        return dp[0];
    }
};