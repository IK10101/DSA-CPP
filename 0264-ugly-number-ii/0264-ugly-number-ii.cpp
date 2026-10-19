class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n, 1);
        int p2 = 0;
        int p3 = 0;
        int p5 = 0;

        for (int i = 1; i < n; i++) {
            int n2 = ugly[p2] * 2;
            int n3 = ugly[p3] * 3;
            int n5 = ugly[p5] * 5;
            ugly[i] = min({n2, n3, n5});

            if (ugly[i] == n2)
                p2++;
            if (ugly[i] == n3)
                p3++;
            if (ugly[i] == n5)
                p5++;
        }
        return ugly[n - 1];
    }
};