class Solution {
private:
    bool f(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0)
            return true;
        if (ind == 0)
            return nums[0] == target;
        if (dp[ind][target] != -1) {
            return dp[ind][target];
        }
        bool notTake = f(ind - 1, target, nums, dp);
        bool take = false;
        if (nums[ind] <= target) {
            take = f(ind - 1, target - nums[ind], nums, dp);
        }
        return dp[ind][target] = take || notTake;
    }

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

        vector<vector<int>> dp(n, vector<int>(target + 1, -1));

        return f(n - 1, target, nums, dp);
    }
    };