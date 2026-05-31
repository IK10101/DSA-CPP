//Problem statement
/* Given N cards arranged in a row, each card has an associated score denoted by the cardScore array.

Choose exactly k cards. In each step, a card can be chosen either from the beginning or the end of the row.

The score is the sum of the scores of the chosen cards.



Return the maximum score that can be obtained.*/

#include <vector>
using namespace std;

class Solution {
   public:
    int maxScore(vector<int>& cardScore, int k) {
        int n = cardScore.size();
        int lsum = 0;
        int rsum = 0;
        int maxsum = 0;
        for (int i = 0; i < k; i++) {
            lsum = lsum + cardScore[i];
            maxsum = lsum;
        }
        int rightindex = n - 1;
        for (int i = k - 1; i >= 0; i--) {
            lsum = lsum - cardScore[i];
            rsum = rsum + cardScore[rightindex];
            rightindex--;
            maxsum = max(maxsum, lsum + rsum);
        }
        return maxsum;
    }
};

//Time complexity: O(k)
//Space complexity: O(1)