class Solution {
private:
    int solve(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if (l == r)
            return nums[l];
        if (dp[l][r] != -1)
            return dp[l][r];
        int left = nums[l] - solve(l + 1, r, nums, dp);
        int right = nums[r] - solve(l, r - 1, nums, dp);
        return dp[l][r] = max(left, right);
    }

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return (solve(0, n - 1, nums, dp) >= 0);
    }
};