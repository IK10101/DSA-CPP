class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int cheapprice = INT_MAX;
        for (auto i : items) {
            cheapprice = min(cheapprice, i[1]);
        }
        vector<int> freecopy(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freecopy[i]++;
                }
            }
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i< n; i++) {
            int p = items[i][1];
            for (int b = budget; b >= p; b--) {
                dp[b] = max(dp[b], dp[b - p] + freecopy[i] + 1);
            }
        }
        int ans = 0;
        for (int b = 0; b <= budget; b++) {
            ans = max(ans, dp[b] + (budget - b) / cheapprice);
        }
        return ans;
    }
};