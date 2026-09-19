class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int aheadBuy, aheadnotBuy, currBuy, currnotBuy;
        aheadnotBuy = aheadBuy = 0;

        for (int ind = n - 1; ind >= 0; ind--) {

            int profit = 0;

            currBuy = max(-prices[ind] + aheadnotBuy, 0 + aheadBuy);

            currnotBuy = max(prices[ind] + aheadBuy, 0 + aheadnotBuy);

            aheadBuy = currBuy;
            aheadnotBuy = currnotBuy;
        }
        return aheadBuy;
    }
};