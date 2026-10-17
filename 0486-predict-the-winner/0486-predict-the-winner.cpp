class Solution {

public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for (int l = 0; l < n; l++) {
            curr[l] = nums[l];
        }
        for (int l = n - 1; l >= 0; l--) {
            curr[l] = nums[l];
            for (int r = l + 1; r < n; r++) {
                int left = nums[l] - prev[r];
                int right = nums[r] - curr[r - 1];
                curr[r] = max(left, right);
            }
            prev = curr;
        }
        return prev[n - 1] >= 0;
    }
};