class Solution {
public:
    string digitSum(string s, int k) {
        while (s.size() > k) {
            string res = "";
            for (int i = 0; i < s.size(); i += k) {
                int sum = 0;
                int a = min(i + k, (int)s.size());
                for (int j = i; j < a; j++) {
                    sum += s[j] - '0';
                }
                res += to_string(sum);
            }

            s = res;
        }
        return s;
    }
};