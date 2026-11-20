class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalsum = 0;
        for (int num : nums) {
            totalsum += num;
        }
        int target = totalsum - x;
        if (target < 0)
            return -1;
        int l = 0;
        int sum = 0;
        int ans = -1;
        for (int r = 0; r < n; r++) {
            sum += nums[r];
            while (sum > target) {
                sum -= nums[l];
                l++;
            }
            if (sum == target) {
                ans = max(ans, r - l + 1);
            }
        }
        if (ans == -1)
            return -1;
        return n - ans;
    }
};