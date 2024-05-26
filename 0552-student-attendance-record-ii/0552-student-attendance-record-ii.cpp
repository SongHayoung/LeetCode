class Solution {
    int dp[100001][2][3];
    int mod = 1e9 + 7;
    int helper(int n, int a, int l) {
        if(dp[n][a][l] != -1) return dp[n][a][l];
        int& res = dp[n][a][l] = helper(n-1,a,0);
        if(a == 0)
            res = (res + helper(n-1,a+1,0)) % mod;
        if(l < 2)
            res = (res + helper(n-1,a,l+1)) % mod;
        return res;
    }
public:
    int checkRecord(int n) {
        memset(dp, -1, sizeof dp);
        dp[0][0][0] = dp[0][0][1] = dp[0][0][2] = dp[0][1][0] = dp[0][1][1] = dp[0][1][2] = 1;
        return helper(n, 0, 0);
    }
};