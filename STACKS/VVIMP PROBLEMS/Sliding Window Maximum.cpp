//Problem Statement

/*Given an array of integers and a sliding window size k, find the maximum value in each sliding window of size k.

For example:
Array = [1, 3, -1, -3, 5, 3, 6, 7], k = 3
Output: [3, 3, 5, 5, 6, 7]*/

//Solution-1 (Naive Approach)
#include <iostream>
#include <vector>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    for (int i = 0; i <= nums.size() - k; i++) {
        int maxVal = nums[i];
        for (int j = 1; j < k; j++) {
            maxVal = max(maxVal, nums[i + j]);
        }
        result.push_back(maxVal);
    }
    return result;
}

//Time Complexity: O(N*K) where N is the number of elements in the array and K is the size of the sliding window
//Space Complexity: O(N-K+1) for the result vector



//Solution-2 (Using Deque)
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> result;
    deque<int> dq; // Will store indices of elements in the current window

    for (int i = 0; i < nums.size(); i++) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove indices whose corresponding values are less than the current element
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        // Add the current index to the deque
        dq.push_back(i);

        // The front of the deque is the largest element in the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }
    return result;
}

//Time Complexity: O(N) where N is the number of elements in the array
//Space Complexity: O(K) for the deque which can hold at most K indices at a time
