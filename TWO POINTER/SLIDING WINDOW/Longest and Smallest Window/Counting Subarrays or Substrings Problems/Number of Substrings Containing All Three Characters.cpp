//Problem Statement
/* Given a string s , consisting only of characters 'a' , 'b' , 'c'.Find the number of substrings that contain at least one occurrence of all these characters 'a' , 'b' , 'c'. */

//Brute Force Approach
#include <string>
#include <algorithm>
using namespace std;

class Solution {
   public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int freq[3] = {0};
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                    count++;
                }
            }
        }
        return count;
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
    int numberOfSubstrings(string s) {
        int n = s.size();
        int lastseen[3] = {-1, -1, -1};
        int count = 0;

        for (int i = 0; i < n; i++) {
            lastseen[s[i] - 'a'] = i;
            if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1) {
                count += 1 + min({lastseen[0], lastseen[1], lastseen[2]});
            }
        }
        return count;
    }
};


//Time complexity: O(n)
//Space complexity: O(1)
