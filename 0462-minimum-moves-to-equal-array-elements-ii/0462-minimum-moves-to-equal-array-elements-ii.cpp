class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        nth_element(nums.begin(), nums.begin() + n / 2, nums.end());
        int mini = 0;
        int mid = nums[n / 2];
        for (int i = 0; i < n; i++) {
            mini += abs(nums[i] - mid);
        }
        return mini;
    }
};