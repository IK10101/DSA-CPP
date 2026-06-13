//Problem Statement

/*A celebrity is a person who is known by everyone else at the party but does not know anyone in return. Given a square matrix M of size N x N where M[i][j] is 1 if person i knows person j, and 0 otherwise, determine if there is a celebrity at the party. Return the index of the celebrity or -1 if no such person exists.

Note that M[i][i] is always 0.

Example 1

Input: M = [ [0, 1, 1, 0], [0, 0, 0, 0], [1, 1, 0, 0], [0, 1, 1, 0] ]

Output: 1

Explanation: Person 1 does not know anyone and is known by persons 0, 2, and 3. Therefore, person 1 is the celebrity.*/


//Solution-1 (Brute Force)
#include<bits/stdc++.h>
using namespace std;
class Solution {
   public:
    int celebrity(vector<vector<int>> &M) {
        int n = M.size();
        vector<int> KnowMe(n);
        vector<int> IKnow(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    KnowMe[j]++;
                    IKnow[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (KnowMe[i] == n - 1 && IKnow[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

//Time Complexity : O(N^2)
//Space Complexity : O(N)


//Optimized Approach (Two Pointers)
#include<bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int celebrity(vector<vector<int>> &M) {
        int n = M.size();
        int top = 0;
        int down = n - 1;
        while (top < down) {
            if (M[top][down] == 1) {
                top++;
            } else if (M[down][top] == 1) {
                down--;
            } else {
                top++;
                down--;
            }
        }
        if (top > down) return -1;
        for (int i = 0; i < n; i++) {
            if (i == top) continue;
            if (M[top][i] == 1 || M[i][top] == 0) {
                return -1;
            }
        }
        return top;
    }
};


//Time Complexity : O(N)
//Space Complexity : O(1)





