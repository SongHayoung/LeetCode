class Solution {
public:
    int countCommas(int n) {
        int res = 0;
        for(int i = 1000, op = 0, nxt = 1000; i <= n; i++) {
            if(i == nxt) {
                nxt = nxt * 1000;
                op++;
            }
            res += op;
        }
        return res;
    }
};