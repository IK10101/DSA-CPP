//Problem Statement

//Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

//Example 1:
//Input: heights = [2,1,5,6,2,3]
//Output: 10



//Solution-1 (Brute Force)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int minHeight = heights[i];
            for(int j=i; j<n; j++){
                minHeight = min(minHeight, heights[j]);
                ans = max(ans, minHeight * (j - i + 1));
            }
        }
        return ans;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)



//Solution-2 (Using Stack)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int ans = 0;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                ans = max(ans, height * width);
            }
            st.push(i);
        }
        
        while(!st.empty()){
            int height = heights[st.top()];
            st.pop();
            int width = st.empty() ? n : n - st.top() - 1;
            ans = max(ans, height * width);
        }
        
        return ans;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)