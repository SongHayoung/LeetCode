class Solution {
public:
    int climbStairs(int n) {
        int dp = 1, res = 1;
        for(int i = 2, tmp = 1; i <= n; i++, dp = res, res = tmp) {
            tmp = res + dp;
        }
        return res;
    }
};