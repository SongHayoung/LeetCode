class Solution {
    int dp[201][201];
    int dfs(int l, int r) {
        if(l == r) return 0;
        if(l + 1 == r) return l;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = INT_MAX;
        for(int i = l + 1; i < r; i++) {
            dp[l][r] = min(dp[l][r], i + max(dfs(l,i-1),dfs(i+1,r)));
        }
        return dp[l][r];
    }
public:
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return dfs(1,n);
    }
};