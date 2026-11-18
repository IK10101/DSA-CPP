class Solution {
private:
    int solve(int i, vector<int>& pts, vector<int>& nums, vector<int>& dp,
              int maxi) {
        if (i > maxi)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int take = pts[i] + solve(i + 2, pts, nums, dp, maxi);
        int notTake = 0 + solve(i + 1, pts, nums, dp, maxi);
        return dp[i] = max(take, notTake);
    }

public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end());
        vector<int> pts(maxi + 1);
        vector<int> dp(maxi + 1, -1);
        for (int x : nums) {
            pts[x] += x;
        }
        return solve(0, pts, nums, dp, maxi);
    }
};