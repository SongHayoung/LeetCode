class Solution {
    long long dp[1010][1010], mod = 1e9 + 7, K;
    long long helper(int n, int k) {
        if(k > n) return 0;
        if(n == k or k == 1) return 1;
        if(dp[n][k] != -1) return dp[n][k];
        return dp[n][k] = (helper(n-1,k-1) + helper(n-1,k) * k % mod) % mod;
    }
    
public:
    int waysToDistribute(int n, int k) {
        K = k;
        memset(dp,-1,sizeof dp);
        return helper(n,k);
    }
};