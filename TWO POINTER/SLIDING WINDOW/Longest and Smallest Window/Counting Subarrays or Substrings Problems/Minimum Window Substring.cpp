//Problem Statement
/* Given two strings s and t, return the minimum window in s which will contain all the characters in t. If there is no such window in s that covers all characters in t, return the empty string "". */

//Brute Force Approach
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int minlen = INT_MAX;
        int sindex = -1;
        for (int i = 0; i < n; i++) {
            int hash[256] = {0};
            for (int j = 0; j < m; j++) {
                hash[t[j]]++;
            }
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (hash[s[j]] > 0) {
                    cnt++;
                }
                hash[s[j]]--;

                if (cnt == t.size()) {
                    if (j - i + 1 < minlen) {
                        minlen = j - i + 1;
                        sindex = i;
                    }

                    break;
                }
            }
        }
        return (sindex == -1) ? "" : s.substr(sindex, minlen);
    }
};

//Time complexity: O(n^2)
//Space complexity: O(1)


//Optimized Approach

#include <string>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
   public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int hash[256] = {0};
        int l = 0;
        int r = 0;
        int minlen = INT_MAX;
        int sindex = -1;
        int cnt = 0;
        for (char ch : t) {
            hash[ch]++;
        }
        while (r < n) {
            if (hash[s[r]] > 0) {
                cnt++;
            }
            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    sindex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    cnt--;
                }
                l++;
            }

            r++;
        }
        return (sindex == -1) ? "" : s.substr(sindex, minlen);
    }
};

//Time complexity: O(n)
//Space complexity: O(1)
