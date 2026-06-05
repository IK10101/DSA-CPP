//Problem Statement
 /*Given a circular integer array arr, return the next greater element for every element in arr.

The next greater element for an element x is the first element greater than x that we come across while traversing the array in a clockwise manner.

If it doesn't exist, return -1 for that element.*/


//Solution-1 (Brute Force)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < i + n; j++) {
                int ind = j % n;
                if (arr[ind] > arr[i]) {
                    nge[i] = arr[ind];
                    break;
                }
            }
        }
        return nge;
    }
};


//Time Complexity: O(N^2)
//Space Complexity: O(N)


//Solution-2 (Monotonic Stack)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
   public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i % n]) {
                st.pop();
            }
            if (i < n) {
                if (st.empty()) {
                    nge[i] = -1;
                } else {
                    nge[i] = st.top();
                }
            }
            st.push(arr[i % n]);
        }
        return nge;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)
