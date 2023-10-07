class Solution {
    long long dp[51][101][51]{0,};
    int mod = 1e9 + 7;
    long long helper(int n, int m, int k, int p, int v) {
        if(p == n) return k == 0;
        if(k < 0) return 0;
        if(dp[p][v][k]) return dp[p][v][k]-1;
        long long & res = dp[p][v][k] = 1;
        for(int i = 1; i <= m; i++) {
            res = (res + helper(n,m, k-(i > v), p+1, max(i,v))) % mod;
        }
        return res - 1;
    }
public:
    int numOfArrays(int n, int m, int k) {
        return helper(n,m,k,0,0);
    }
};