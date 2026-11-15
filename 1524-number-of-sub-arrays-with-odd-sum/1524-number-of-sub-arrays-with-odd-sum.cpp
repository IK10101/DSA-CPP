class Solution {
public:
    const int MOD = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int odd = 0;
        int even = 1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];

            if (sum % 2 == 0) {
                cnt = (cnt + odd) % MOD;
                even++;
            } else {
                cnt = (cnt + even) % MOD;
                odd++;
            }
        }
        return cnt % MOD;
    }
};