class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if (sum % 2 != 0)
            return false;

        int target = sum / 2;

        vector<vector<int>> dp(n, vector<int>(target + 1, 0));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        if (nums[0] <= target) {
            dp[0][nums[0]] = true;
        }

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= target; j++) {
                bool notTake = dp[ind - 1][j];
                bool take = false;
                if (nums[ind] <= j) {
                    take = dp[ind - 1][j - nums[ind]];
                }
                dp[ind][j] = notTake || take;
            }
        }

        return dp[n - 1][target];
    }
};