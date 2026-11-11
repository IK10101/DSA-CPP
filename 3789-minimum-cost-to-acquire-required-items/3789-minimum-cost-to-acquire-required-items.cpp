class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {
        long long choice1 = 1ll * need1 * cost1 + 1ll * need2 * cost2;
        long long both = min(need1, need2);
        long long choice2 = 1ll * both * costBoth;

        if (need1 > need2) {
            choice2 += 1ll * (need1 - need2) * cost1;

        } else {
            choice2 += 1ll * (need2 - need1) * cost2;
        }

        long long choice3 = 1ll * max(need1, need2) * costBoth;

        return min({choice1, choice2, choice3});
    }
};