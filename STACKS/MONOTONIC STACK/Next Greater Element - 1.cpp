//Problem Statement

/*Given an array arr of size n containing elements, find the next greater element for each element in the array in the order of their appearance.

The next greater element of an element in the array is the nearest element on the right that is greater than the current element.

If there does not exist a next greater element for the current element, then the next greater element for that element is -1.*/


//Solution-1 (Brute Force)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    nge[i] = arr[j];
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
    vector<int> nextLargerElement(vector<int> arr) {
        int n = arr.size();
        vector<int> nge(n, -1);
        stack<int> st;
        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = -1;
            } else {
                nge[i] = st.top();
            }
            st.push(arr[i]);
        }
        return nge;
    }
};


//Time Complexity: O(N)
//Space Complexity: O(N)

