//Problem Statement
/* Find the validity of an input string s that only contains the letters '(', ')' and '*'.



A string entered is legitimate if

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".*/

#include <string>
using namespace std;
class Solution {
   public:
    bool isValid(string s) {
        int min = 0;
        int max = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                min++;
                max++;
            } else if (s[i] == ')') {
                min--;
                max--;
            } else if (s[i] == '*') {
                min--;
                max++;
            }
            if (max < 0) return false;
            if (min < 0) min = 0;
        }
        return (min == 0);
    }
};

//Time Complexity: O(N) where N is the length of the input string s, as we need to iterate through the string once.
//Space Complexity: O(1) as we are using only a constant amount of extra space
