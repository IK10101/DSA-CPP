class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<long long> ugly(n, 1);
        vector<long long> ind(k, 0);

        for (int i = 1; i < n; i++) {
            long long next = INT_MAX;
            for (int j = 0; j < k; j++) {
                next = min(next, 1ll * ugly[ind[j]] * primes[j]);
            }
            ugly[i] = next;
            for (int j = 0; j < k; j++) {
                if (ugly[ind[j]] * primes[j] == next)
                    ind[j]++;
            }
        }
        return ugly[n - 1];
    }
};