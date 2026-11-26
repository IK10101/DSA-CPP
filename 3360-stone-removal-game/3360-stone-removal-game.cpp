class Solution {
public:
    bool canAliceWin(int n) {
        int a = 0;
        int v = 10;
        while (n >= v) {
            n -= v;
            v--;
            a++;
        }
        return (a % 2 == 1);
    }
};