class Solution {
public:
    int climbStairs(int n) {
        int a = 1, res = 1, tmp = 1;
        for(int i = 2; i <= n; i++) {
            tmp = res + a;
            a = res;
            res = tmp;
        }
        return res;
    }
};