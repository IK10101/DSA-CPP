class Solution {
public:
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0)
                return 2;

            if (target == 0 || target == nums[0])
                return 1;

            return 0;
        }

        if (dp[ind][target] != -1)
            return dp[ind][target];

        int notTake = solve(ind - 1, target, nums, dp);

        int take = 0;
        if (nums[ind] <= target) {
            take = solve(ind - 1, target - nums[ind], nums, dp);
        }

        return dp[ind][target] = (take + notTake);
    }

    int perfectSum(vector<int>& nums, int K) {
        int n = nums.size();

        vector<vector<int>> dp(n, vector<int>(K + 1, -1));

        return solve(n - 1, K, nums, dp);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totsum = 0;
        for (auto& it : nums) {
            totsum += it;
        }
        if (totsum - target < 0 || (totsum - target) % 2 != 0)
            return 0;
        return perfectSum(nums, (totsum - target) / 2);
    }
};