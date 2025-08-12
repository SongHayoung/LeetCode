class Solution {
    long long dp[333][333], mod = 1e9 + 7;
    long long helper(int n, int lim) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n][lim] != -1) return dp[n][lim];
        long long& res = dp[n][lim] = 0;
        for(int i = 1; i <= lim; i++) {
            res = (res + helper(n-i,i-1)) % mod;
        }
        return res;
    }
    int helper(int n) {
        memset(dp, -1, sizeof dp);
        return helper(n,n);
    }
    void helper(vector<int>& A, int n, int p, int& res) {
        if(n < 0) return;
        if(n == 0) {
            res += 1;
            return;
        }
        if(p == A.size()) return;
        helper(A,n-A[p],p+1,res);
        helper(A,n,p+1,res);
    }
public:
    int numberOfWays(int n, int x) {
        if(x == 1) return helper(n);
        vector<int> cand;
        for(int i = 1; ; i++) {
            int now = pow(i,x);
            if(now > n) break;
            cand.push_back(now);
        }
        int res = 0;
        helper(cand,n,0,res);
        return res;
    }
};
