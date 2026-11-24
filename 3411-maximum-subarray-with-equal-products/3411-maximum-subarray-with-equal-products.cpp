class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 2;
        int prodVal = 1;

        int l = 0, r = 0;

        while (r < n) {
            while (gcd(prodVal, nums[r]) > 1) {
                prodVal /= nums[l];
                l++;
            }
            prodVal *= nums[r];
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};