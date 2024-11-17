class Solution {
    long long mod = 1e9 + 7;
    long long dp[777][777][2];
    long long helper(int n, int k, int prv, int o, int e) {        
        if(k < 0) return 0;
        if(n == 0) return k == 0;
        if(dp[n][k][prv] != -1) return dp[n][k][prv];
        return dp[n][k][prv] = (helper(n-1,k,1,o,e) * o % mod + helper(n-1, k - !prv, 0, o, e) * e % mod) % mod;
    }
public:
    int countOfArrays(int n, int m, int k) {
        memset(dp,-1,sizeof dp);
        long long o = (m + 1) / 2, e = m / 2;
        return (helper(n-1,k,1,o,e) * o % mod + helper(n-1,k,0,o,e) * e % mod) % mod;
    }
};