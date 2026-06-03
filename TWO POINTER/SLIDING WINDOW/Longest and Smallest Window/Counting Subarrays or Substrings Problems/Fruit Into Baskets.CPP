//Problem Statement
/*There is only one row of fruit trees on the farm, oriented left to right. An integer array called fruits represents the trees, where fruits[i] denotes the kind of fruit produced by the ith tree.


The goal is to gather as much fruit as possible, adhering to the owner's stringent rules:


1) There are two baskets available, and each basket can only contain one kind of fruit. The quantity of fruit each basket can contain is unlimited.

2) Start at any tree, but as you proceed to the right, select exactly one fruit from each tree, including the starting tree. One of the baskets must hold the harvested fruits.

3) Once reaching a tree with fruit that cannot fit into any basket, stop.

Return the maximum number of fruits that can be picked.*/

//Brute Force Approach
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int totalFruits(vector<int>& fruits) {
        int n = fruits.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mpp;
            for (int j = i; j < n; j++) {
                mpp[fruits[j]]++;

                if (mpp.size() > 2) break;
                ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

//Time complexity: O(n^2)
//Space complexity: O(n)

//Optimized Approach
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int totalFruits(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int n = fruits.size();
        unordered_map<int, int> mpp;
        while (right < n) {
            mpp[fruits[right]]++;

            if (mpp.size() > 2) {
                mpp[fruits[left]]--;
                if (mpp[fruits[left]] == 0) {
                    mpp.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};

//Time complexity: O(n)
//Space complexity: O(n)