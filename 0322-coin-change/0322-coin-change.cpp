class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
        vector<int> curr(amount + 1, 0);
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0) {
                prev[T] = T / coins[0];
            } else
                prev[T] = 1e9;
        }
        for (int ind = 1; ind < n; ind++) {
            for (int tar = 0; tar <= amount; tar++) {
                int notPick = 0 + prev[tar];
                int pick = INT_MAX;
                if (coins[ind] <= tar)
                    pick = 1 + curr[tar - coins[ind]];
                curr[tar] = min(pick, notPick);
            }
            prev = curr;
        }
        int ans = prev[amount];
        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};