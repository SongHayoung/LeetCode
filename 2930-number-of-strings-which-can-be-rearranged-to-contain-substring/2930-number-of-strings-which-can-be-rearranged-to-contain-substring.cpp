
long long dp[101010][3][2][2];
class Solution {
    long long mod = 1e9 + 7;
    long long helper(int n, int e, int l, int t) {
        if(n == 0) return e == 0 and l == 0 and t == 0;
        long long& res = dp[n][e][l][t];
        if(res != -1) return res;
        res = helper(n-1,e,l,t) * (26 - (e > 0) - (l > 0) - (t > 0)) % mod;
        if(e) {
            res = (res + helper(n-1,e-1,l,t)) % mod;
        }
        if(l) {
            res = (res + helper(n - 1, e,l-1,t)) % mod;
        }
        if(t) {
            res = (res + helper(n-1, e, l, t-1)) % mod;
        }
        return res;
    }
public:
    int stringCount(int n) {
        memset(dp,-1,sizeof dp);
        return helper(n,2,1,1);
    }
};

