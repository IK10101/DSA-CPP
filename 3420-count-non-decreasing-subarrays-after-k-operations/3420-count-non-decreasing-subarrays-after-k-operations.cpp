class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<pair<long long, int>> blocks(2 * n + 5);

        int head = n, tail = n;

        int r = n - 1;

        long long originalSum = 0;
        long long adjustedSum = 0;
        long long ans = 0;

        for (int l = n - 1; l >= 0; l--) {

            long long x = nums[l];
            int cnt = 1;

            while (head < tail && blocks[head].first <= x) {

                adjustedSum -= blocks[head].first * blocks[head].second;

                cnt += blocks[head].second;
                head++;
            }

            blocks[--head] = {x, cnt};

            adjustedSum += x * cnt;
            originalSum += x;

            while (adjustedSum - originalSum > k) {

                long long val = blocks[tail - 1].first;

                adjustedSum -= val;
                originalSum -= nums[r];

                if (blocks[tail - 1].second == 1) {
                    tail--;
                } else {
                    blocks[tail - 1].second--;
                }

                r--;
            }

            ans += (r - l + 1);
        }

        return ans;
    }
};