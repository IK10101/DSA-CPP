//Problem Statement

/* You are given an integer array asteroids representing asteroids in a row. Each asteroid moves at the same speed.


The absolute value of an asteroid represents its size. The sign of an asteroid represents its direction: positive (+) means moving right, negative (-) means moving left.

Collision rules:

Asteroids moving in the same direction never collide.
When two asteroids moving in opposite directions collide, the smaller asteroid explodes and the larger asteroid continues moving in the same direction.
If both asteroids are equal in size, both explode.
Collisions are resolved one at a time, from left to right. If an asteroid survives a collision, it continues moving and may collide immediately with the next asteroid in its path.

Return the state of the asteroids after all collisions as an array in the same order.*/


//Solution (Monotonic Stack)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
   public:
    vector<int> asteroidCollision(vector<int> &asteroids) {
        int n = asteroids.size();
        vector<int> st;
        for (int i = 0; i < n; i++) {
            int curr = asteroids[i];
            if (curr > 0)
                st.push_back(curr);
            else {
                while (!st.empty() && st.back() > 0 && abs(curr) > st.back()) {
                    st.pop_back();
                }
                if (!st.empty() && st.back() == abs(curr)) {
                    st.pop_back();
                } else if (st.empty() || st.back() < 0) {
                    st.push_back(curr);
                }
            }
        }

        return st;
    }
};

//Time Complexity: O(n)
//Space Complexity: O(n)
