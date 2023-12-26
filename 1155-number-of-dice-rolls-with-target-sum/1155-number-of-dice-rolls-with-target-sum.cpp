class Solution {
    int dp[31][1001];
    int mod = 1e9 + 7;
    int helper(int n, int& k, int t) {
        if(n == 0) return t == 0;
        if(t <= 0) return 0;
        if(dp[n][t] != -1) return dp[n][t];
        dp[n][t] = 0;
        int ma = min(k,t);
        for(int i = 1; i <= ma; i++) {
            dp[n][t] = (dp[n][t] + helper(n-1,k,t-i)) % mod;
        }
        return dp[n][t];
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return helper(n,k,target);
    }
};