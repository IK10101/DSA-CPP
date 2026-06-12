//Problem Statement

/*Given an array arr of size n, where each element arr[i] represents the stock price on day i. 
Calculate the span of stock prices for each day.
The span Si for a specific day i is defined as the maximum number of consecutive previous days (including the current day) for which the stock price was less than or equal to the price on day i.*/


//Brute-Approach
#include<iostream>
#include<vector>
using namespace std;

class Solution {
   public:
    vector<int> stockSpan(vector<int> arr, int n) {
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int currSpan = 0;

            for (int j = i; j >= 0; j--) {
                if (arr[j] <= arr[i]) {
                    currSpan++;
                }

                else
                    break;
            }

            ans[i] = currSpan;
        }

        return ans;
    }
};

//Time Complexity : O(N^2)
//Space Complexity : O(1)



//Optimal Approach
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
   private:
    vector<int> findPGE(vector<int> arr) {
        int n = arr.size();

        vector<int> ans(n);

        stack<int> st;

        for (int i = 0; i < n; i++) {
            int currEle = arr[i];

            while (!st.empty() && arr[st.top()] <= currEle) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;

            else
                ans[i] = st.top();

            st.push(i);
        }

        return ans;
    }

   public:
    vector<int> stockSpan(vector<int> arr, int n) {
        vector<int> PGE = findPGE(arr);

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = i - PGE[i];
        }

        return ans;
    }
};

//Time Complexity : O(N)
//Space Complexity : O(N)