class Solution {
public:
    int minMoves(vector<int>& nums) {
        int a = *max_element(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans += a - nums[i];
        }
        return ans;
    }
};