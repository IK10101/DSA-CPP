//Problem Statement

/*Given an integer array nums, return the sum of all subarray ranges of nums.
The range of a subarray is the difference between the largest and smallest element in the subarray.
A subarray is a contiguous non-empty sequence of elements within an array.*/

//Solution-1 (Brute Force)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    long long subArrayRanges(vector<int> &nums) {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int minVal = nums[i];
            int maxVal = nums[i];
            for (int j = i; j < n; j++) {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                sum += (maxVal - minVal);
            }
        }
        return sum;
    }
};


//Time Complexity: O(N^2)
//Space Complexity: O(1)


//Solution-2 (Monotonic Stack)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
   private:
    vector<int> FindPSE(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

   private:
    vector<int> FindNSE(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int curr = nums[i];
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

   private:
    vector<int> FindPGE(vector<int> &nums) {
        int n = nums.size();
        vector<int> pge(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                pge[i] = -1;
            } else {
                pge[i] = st.top();
            }
            st.push(i);
        }
        return pge;
    }

   private:
    vector<int> FindNGE(vector<int> &nums) {
        int n = nums.size();
        vector<int> nge(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = n;
            } else {
                nge[i] = st.top();
            }
            st.push(i);
        }
        return nge;
    }

   public:
    long long subArrayRanges(vector<int> &nums) {
        vector<int> PSE = FindPSE(nums);
        vector<int> NSE = FindNSE(nums);
        vector<int> PGE = FindPGE(nums);
        vector<int> NGE = FindNGE(nums);
        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long minCount = 1ll * (i - PSE[i]) * (NSE[i] - i);
            long long maxCount = 1ll * (i - PGE[i]) * (NGE[i] - i);
            long long minContribution = 1LL * nums[i] * minCount;
            long long maxContribution = 1LL * nums[i] * maxCount;
            sum += (maxContribution - minContribution);
        }
        return sum;
    }
};


//Time Complexity: O(N)
//Space Complexity: O(N)