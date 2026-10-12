class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (int i = 2; i <= n; i++) {
            string temp = "";

            for (int j = 0; j < s.size();) {
                int count = 0;
                char ch = s[j];

                while (j < s.size() && s[j] == ch) {
                    count++;
                    j++;
                }

                temp += to_string(count) + ch;
            }

            s = temp;
        }

        return s;
    }
};