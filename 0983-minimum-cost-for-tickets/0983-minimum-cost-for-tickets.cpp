class Solution {

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            int next1 = i + 1;
            int j = i;
            while (j < n && days[j] <= days[i] + 6) {
                j++;
            }
            int next2 = j;
            int k = i;
            while (k < n && days[k] <= days[i] + 29) {
                k++;
            }
            int next3 = k;

            int cost = min({costs[0] + dp[next1], costs[1] + dp[next2],
                            costs[2] + dp[next3]});

            dp[i] = cost;
        }
        return dp[0];
    }
};