class Solution {

public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> prev(m + 1, 0);
        vector<int> curr(m + 1, 0);
        int mini = 0;
        for (int j = 0; j <= m; j++)
            prev[j] = j;
        for (int i = 1; i <= n; i++) {
            curr[0] = i;
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = 0 + prev[j - 1];
                } else {
                    int insert = 1 + curr[j - 1];
                    int deleted = 1 + prev[j];
                    int replace = 1 + prev[j - 1];
                    mini = min(insert, deleted);
                    curr[j] = min(mini, replace);
                }
            }
            prev = curr;
        }

        return prev[m];
    }
};