//Problem Statement

/*Given a string num representing a non-negative integer and an integer k, remove k digits from the number so that the new number is the smallest possible.
Return the new number as a string.*/

//Solution-1 (Brute Force)
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string removeKdigits(string nums, int k) {
        string st;
        for (char ch : nums) {
            while (!st.empty() && k > 0 && st.back() > ch) {
                st.pop_back();
                k--;
            }
            st.push_back(ch);
        }
        while (!st.empty() && k > 0) {
            st.pop_back();
            k--;
        }
        int i = 0;
        while (i < st.size() && st[i] == '0') i++;

        string res = st.substr(i);

        return res.empty() ? "0" : res;
    }
};

//Time Complexity: O(N)
//Space Complexity: O(N)

