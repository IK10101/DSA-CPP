//Problem Statement
/* A line of N kids is standing there. The rating values listed in the integer array ratings are assigned to each kid.



These kids are receiving candy, according to the following criteria:



There must be at least one candy for every child.


Kids whose scores are higher than their neighbours receive more candies than their neighbours.


Return the minimum number of candies needed to distribute among children.*/

#include <vector>
using namespace std;

class Solution {
   public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i + 1] + 1, candies[i]);
            }
        }
        int sum = 0;
        for (int candy : candies) {
            sum += candy;
        }
        return sum;
    }
};

//Time Complexity: O(N) where N is the number of kids, as we need to iterate through the ratings array twice.
//Space Complexity: O(N) for the candies array that stores the number of candies for each kid.