class Solution {
    long long dp[202][202], c[202][202];
    long long helper(int n, int m) {
        if(dp[n][m] != -1) return dp[n][m];
        long long& res = dp[n][m] = c[n][m];
        for(int i = 1; i < n; i++) {
            res = max(res, helper(i,m) + helper(n - i,m));
        }
        for(int j = 1; j < m; j++) {
            res = max(res, helper(n,j) + helper(n,m-j));
        }
        return res;
    }
public:
    long long sellingWood(int n, int m, vector<vector<int>>& prices) {
        memset(dp,-1,sizeof dp);
        memset(c,0,sizeof c);
        for(auto& p : prices) {
            c[p[0]][p[1]] = max(c[p[0]][p[1]], 1ll * p[2]);
        }
        return helper(n,m);
    }
};