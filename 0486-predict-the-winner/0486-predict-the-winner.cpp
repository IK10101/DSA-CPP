class Solution {

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 0; l < n; l++) {
            dp[l][l] = nums[l];
        }
        for (int l = n - 1; l >= 0; l--) {
            for (int r = l + 1; r < n; r++) {
                int left = nums[l] - dp[l + 1][r];
                int right = nums[r] - dp[l][r - 1];
                dp[l][r] = max(left, right);
            }
        }
        return dp[0][n - 1] >= 0;
    }
};