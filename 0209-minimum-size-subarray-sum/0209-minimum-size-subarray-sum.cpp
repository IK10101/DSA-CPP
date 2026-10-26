class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;

        int i = 0;
        int sum = 0;
        int len = 0;
        for (int j = 0; j < n; j++) {
            sum += nums[j];

            while (sum >= target) {
                len = j - i + 1;
                mini = min(mini, len);
                sum -= nums[i];
                i++;
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};