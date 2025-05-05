class Solution {
    int dp[1001];
    int mod = 1e9 + 7;
    int helper(int n) {
        if(n < 0) return 0;
        if(n <= 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;
        if(dp[n] != -1) return dp[n];
        dp[n] = 0;
        dp[n] = (dp[n] + 2 * helper(n - 1)) % mod;
        dp[n] = (dp[n] + helper(n - 3)) % mod;
        return dp[n];
    }
public:
    int numTilings(int n) {
        memset(dp, -1, sizeof dp);
        return helper(n);
    }
};