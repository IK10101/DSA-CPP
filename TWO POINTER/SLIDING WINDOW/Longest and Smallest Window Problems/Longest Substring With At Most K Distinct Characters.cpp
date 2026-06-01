//Problem Statement
/* Given a string s and an integer k, return the length of the longest substring of s that contains at most k distinct characters. */

//Brute Force Approach
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int kDistinctChar(string& s, int k) {
        int maxlen = 0;
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.size(); i++) {
            mpp.clear();
            for (int j = i; j < s.size(); j++) {
                mpp[s[j]]++;
                if (mpp.size() <= k) {
                    maxlen = max(maxlen, j - i + 1);
                } else {
                    break;
                }
            }
        }
        return maxlen;
    }
};

//Time complexity: O(n^2)
//Space complexity: O(k)

//Optimized Approach
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int kDistinctChar(string& s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;
        unordered_map<char, int> mpp;
        while (right < n) {
            (mpp[s[right]])++;
            while (mpp.size() > k) {
                mpp[s[left]]--;
                if (mpp[s[left]] == 0) {
                    mpp.erase(s[left]);
                }
                left++;
            }

            if (mpp.size() <= k) {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};

//Time complexity: O(n)
//Space complexity: O(k)


