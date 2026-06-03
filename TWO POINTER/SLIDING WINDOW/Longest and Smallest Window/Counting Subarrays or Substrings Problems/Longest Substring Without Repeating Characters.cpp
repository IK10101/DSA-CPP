//Problem Statement
/* Given a string s, find the length of the longest substring without repeating characters. */

//Brute Force Approach
#include <string>
using namespace std;


class Solution {
   public:
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        int maxlen = 0;
        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                if (temp.find(s[j]) == string::npos) {
                    temp = temp + s[j];
                } else {
                    break;
                }
            }
            int len = temp.size();
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};

//Time complexity: O(n^3)
//Space complexity: O(n)

//Optimized Approach
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
   public:
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();

        int Hashlen = 256;
        int hash[Hashlen];

        for (int i = 0; i < Hashlen; i++) {
            hash[i] = -1;
        }

        int l = 0;
        int r = 0;
        int maxlen = 0;
        while (r < n) {
            if (hash[s[r]] != -1) {
                l = max(hash[s[r]] + 1, l);
            }

            int len = r - l + 1;
            maxlen = max(maxlen, len);
            hash[s[r]] = r;
            r++;
        }
        return maxlen;
    }
};

//Time complexity: O(n)
//Space complexity: O(1)
