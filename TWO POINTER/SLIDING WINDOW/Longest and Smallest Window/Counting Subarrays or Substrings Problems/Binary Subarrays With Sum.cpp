//Problem Statement
/* Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal. A subarray is a contiguous part of the array. */

//Approach
#include <vector>
using namespace std;

class Solution {
   private:
    int numSubarraysWithSumLessthanEqualtoGoal(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int l = 0;
        int r = 0;
        int count = 0;
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLessthanEqualtoGoal(nums, goal) -
               numSubarraysWithSumLessthanEqualtoGoal(nums, goal - 1);
    }
};

//Time complexity: O(n)
//Space complexity: O(1)