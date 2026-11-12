class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return;
        k = k % n;

        // reverse whole arr
        reverse(nums.begin(), nums.end());
        // reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // reverse the n - k elements
        reverse(nums.begin() + k, nums.end());
    }
};