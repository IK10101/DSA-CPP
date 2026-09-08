class Solution {
private:
    int f(int ind, int start, vector<int>& nums, vector<int>& dp) {
        if (ind == start)
            return nums[ind];
        if (ind < start)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int pick = nums[ind] + f(ind - 2, start, nums, dp);
        int notPick = 0 + f(ind - 1, start, nums, dp);

        return dp[ind] = max(pick, notPick);
    }

public:
    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 0)
            return 0;

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        int case1 = f(n - 2, 0, nums, dp1);

        vector<int> dp2(n, -1);
        int case2 = f(n - 1, 1, nums, dp2);

        return max(case1, case2);
    }
};