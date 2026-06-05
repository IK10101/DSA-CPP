//Problem Statement

/*Given an array of integers arr of size n, calculate the sum of the minimum value in each (contiguous) subarray of arr. Since the result may be large, return the answer modulo 109 +7.*/

//Solution-1 (Brute Force)

#include <iostream> 
#include <vector>
using namespace std;
class Solution {
   public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int mini = arr[i];
            for (int j = i; j < n; j++) {
                mini = min(mini, arr[j]);
                sum += mini;
                sum = sum % mod;
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
    vector<int> findNSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }

   private:
    vector<int> findPSE(vector<int> &arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }

   public:
    int sumSubarrayMins(vector<int> &arr) {
        vector<int> nse = findNSE(arr);
        vector<int> pse = findPSE(arr);
        int n = arr.size();
        int mod = 1e9 + 7;
        int sum=0;
        for (int i = 0; i < n; i++) {
            int left = i - pse[i];
            int right = nse[i] - i;
            long long freq = left * right * 1LL;
            int val = (freq * arr[i] * 1LL) % mod;
            sum = (sum + val) % mod;
        }
        return sum;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)
