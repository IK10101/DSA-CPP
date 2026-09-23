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

        vector<int> ahead(target + 1, 0);
        ahead[0] = true;

        if (nums[0] <= target)
            ahead[nums[0]] = true;

        vector<int> curr(target + 1, 0);

        for (int ind = 1; ind < n; ind++) {
            for (int j = 0; j <= target; j++) {
                bool notTake = ahead[j];
                bool take = false;
                if (nums[ind] <= j) {
                    take = ahead[j - nums[ind]];
                }
                curr[j] = notTake || take;
            }
            ahead = curr;
        }

        return ahead[target];
    }
};