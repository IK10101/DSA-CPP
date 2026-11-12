class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 1;
        int incre = 1;
        int decre = 1;
        for (int i = 1; i < n; i++) {

            if (nums[i] > nums[i - 1]) {
                incre++;
                decre = 1;
            } else if (nums[i] < nums[i - 1]) {
                decre++;
                incre = 1;
            } else if (nums[i] == nums[i - 1]) {
                incre = decre = 1;
            }
            maxi = max({maxi, incre, decre});
        }
        return maxi;
    }
};