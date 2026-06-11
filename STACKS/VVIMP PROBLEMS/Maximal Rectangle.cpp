//Problem Statement

/*Given a m x n binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/

/* Input: matrix = [[1, 0, 1, 0, 0], [1, 0, 1, 1, 1], [1, 1, 1, 1, 1], [1, 0, 0, 1, 0]]

Output: 6

Explanation: The highlighted part depicts the rectangle with the largest area i.e. 6. */


//Solution 
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
   private:
    int largestRectangleArea(vector<int> &prefixSum) {
        stack<int> st;
        int maxArea = 0;
        int area;
        int nse, pse;
        for (int i = 0; i < prefixSum.size(); i++) {
            while (!st.empty() && prefixSum[st.top()] >= prefixSum[i]) {
                int element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                area = prefixSum[element] * (nse - pse - 1);
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        while (!st.empty()) {
            nse = prefixSum.size();

            int element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();

            area = prefixSum[element] * (nse - pse - 1);
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }

   public:
    int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> prefixSum(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0)
                    prefixSum[j] = 0;
                else
                    prefixSum[j]++;
            }
            maxArea = max(maxArea, largestRectangleArea(prefixSum));
        }
        return maxArea;
    }
};

//Time Complexity : o(M*N) + O(N*2M)
//Space Complexity : O(N*M) + O(N)

