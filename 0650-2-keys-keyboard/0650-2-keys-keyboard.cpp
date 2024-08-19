class Solution {
    int dp[1010];
    int helper(int x, int n) {
        if(x > n) return 1010;
        if(x == n) return 0;
        if(dp[x] != -1) return dp[x];
        int& res = dp[x] = 2020;
        for(int i = 1; x * (i + 1) <= n; i++) {
            res = min(res, helper(x * (i + 1), n) + i + 1);
        }
        return res;
    }
public:
    int minSteps(int n) {
        memset(dp,-1,sizeof dp);
        return helper(1,n);
    }
};