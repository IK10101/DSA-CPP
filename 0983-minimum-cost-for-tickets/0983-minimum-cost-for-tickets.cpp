class Solution {
private:
    int solve(int i, vector<int>& days, vector<int>& costs, vector<int>& dp) {
        int n = days.size();
        if (i == days.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
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

        int cost = min({costs[0] + solve(next1, days, costs, dp),
                        costs[1] + solve(next2, days, costs, dp),
                        costs[2] + solve(next3, days, costs, dp)});

        return dp[i] = cost;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, -1);
        return solve(0, days, costs, dp);
    }
};