//Problem Statement
/* Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's. */

//Brute Force Approach
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            int zerocount = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) zerocount++;
                if (zerocount <= k)
                    maxlen = max(maxlen, j - i + 1);
                else
                    break;
            }
        }
        return maxlen;
    }
};

//Time complexity: O(n^2)
//Space complexity: O(1)

//Optimized Approach
#include <vector>
using namespace std;

class Solution {
   public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int zeros = 0;

        while (right < n) {
            if (nums[right] == 0) zeros++;
            if (zeros > k) {
                if (nums[left] == 0) {
                    zeros--;
                }
                left++;
            }
            if (zeros <= k) {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)