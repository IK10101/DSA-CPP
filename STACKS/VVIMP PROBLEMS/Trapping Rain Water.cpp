//Problem Statement

//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

//Example 1:
//Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
//Output: 6



//Solution-1 (Brute Force)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        for(int i=0; i<n; i++){
            int leftMax = 0, rightMax = 0;
            for(int j=0; j<=i; j++){
                leftMax = max(leftMax, height[j]);
            }
            for(int j=i; j<n; j++){
                rightMax = max(rightMax, height[j]);
            }
            ans += min(leftMax, rightMax) - height[i];
        }
        return ans;
    }
};

//Time Complexity: O(n^2)
//Space Complexity: O(1)
 

//Solution-2 (Prefix and Suffix Arrays)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        
        vector<int> leftMax(n), rightMax(n);
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }
        
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }
        
        int ans = 0;
        for(int i=0; i<n; i++){
            ans += min(leftMax[i], rightMax[i]) - height[i];
        }
        
        return ans;
    }
};


//Time Complexity: O(n)
//Space Complexity: O(n)


//Solution-3 (Two Pointers)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n == 0) return 0;
        
        int left = 0, right = n-1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        
        while(left <= right){
            if(height[left] < height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                } else {
                    ans += leftMax - height[left];
                }
                left++;
            } else {
                if(height[right] >= rightMax){
                    rightMax = height[right];
                } else {
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        
        return ans;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(1)
