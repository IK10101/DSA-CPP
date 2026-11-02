class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mini = 0;
        int n = nums.size();
        int low = nums[0];
        int high = nums[n - 1];
        int mid = nums[n / 2];
        for (int i = 0; i < n; i++) {
            mini += abs(nums[i] - mid);
        }
        return mini;
    }
};