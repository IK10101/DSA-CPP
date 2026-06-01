//Problem Statement
/* Given an integer k and a string s, any character in the string can be selected and changed to any other uppercase English character. This operation can be performed up to k times. After completing these steps, return the length of the longest substring that contains the same letter.*/

//Brute Force Approach
#include <string>
#include <algorithm>
using namespace std;

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int maxlen = 0;
        ;
        for (int i = 0; i < n; i++) {
            int hash[26] = {0};
            int maxf = 0;
            for (int j = i; j < n; j++) {
                hash[s[j] - 'A']++;
                maxf = max(maxf, hash[s[j] - 'A']);
                int changes = (j - i + 1) - maxf;
                if (changes <= k) {
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
//Space complexity: O(1)

//Optimized Approach
#include <string>
#include <algorithm>
using namespace std;

class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int hash[26] = {0};
        int maxf = 0;
        int len = right - left + 1;
        while (right < n) {
            hash[s[right]-'A']++;
            maxf = max(maxf, hash[s[right]-'A']);
            while ((right - left + 1) - maxf > k) {
                hash[s[left]-'A']--;
                left++;
                maxf = 0;
                for (int i = 0; i < 26; i++) {
                    maxf = max(maxf, hash[i]);
                }
                
            }
            if ((right - left + 1) - maxf <= k) {
                    maxlen = max(maxlen, right - left + 1);
                }
            right++;
        }
        return maxlen;
    }
};

//Time complexity: O(n*26) => O(n)
//Space complexity: O(1)