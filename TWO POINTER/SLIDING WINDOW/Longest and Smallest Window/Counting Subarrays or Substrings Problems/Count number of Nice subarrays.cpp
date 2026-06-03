//Problem Statement
/* Given an array of integers nums and an integer k, return the number of nice subarrays. A subarray is nice if it contains exactly k odd numbers. */

//Approach
#include <vector>
using namespace std;

class Solution {
   private:
    int numberOfOddSubarraysAtmostK(vector<int>& nums, int k) {
        if (k < 0) return 0;
        int l = 0;
        int r = 0;
        int count = 0;
        int oddcount = 0;
        while (r < nums.size()) {
            oddcount += nums[r] % 2;
            while (oddcount > k) {
                oddcount -= nums[l] % 2;
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }

   public:
    int numberOfOddSubarrays(vector<int>& nums, int k) {
        return numberOfOddSubarraysAtmostK(nums, k) -
               numberOfOddSubarraysAtmostK(nums, k - 1);
    }
};


//Time complexity: O(n)
//Space complexity: O(1)