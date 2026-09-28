class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1, -1);
        vector<unsigned long long> curr(amount + 1, -1);
        for (int amt = 0; amt <= amount; amt++) {
            prev[amt] = (amt % coins[0] == 0);
        }
        for (int ind = 1; ind < n; ind++) {
            for (int amt = 0; amt <= amount; amt++) {
                unsigned long long notTake = prev[amt];
                unsigned long long take = 0;
                if (coins[ind] <= amt)
                    take = curr[amt-coins[ind]];
                curr[amt] = (take + notTake);
            }
            prev = curr;
        }
        return prev[amount];
    }
};