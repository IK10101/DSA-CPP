class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxprofit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int currprofit = prices[i] - mini;
            maxprofit = max(maxprofit, currprofit);
            mini = min(prices[i], mini);
        }
        return maxprofit;
    }
};