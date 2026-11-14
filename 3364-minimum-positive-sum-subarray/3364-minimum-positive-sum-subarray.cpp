class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = INT_MAX;
        int len = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                len = j - i + 1;
                sum += nums[j];
                if (len >= l && len <= r) {
                    if (sum > 0) {
                        mini = min(sum, mini);
                    }
                }
                if (len >= r)
                    break;
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};