class Solution {
    int dp[5][20001];
    vector<vector<int>> g{{1},{0,2},{0,1,3,4},{2,4},{0}};
    int mod = 1e9 + 7;
    int helper(int n, int v) {
        if(n == 0) return 1;
        if(dp[v][n] != -1) return dp[v][n];
        dp[v][n] = 0;
        for(auto nxt : g[v]) {
            dp[v][n] = (dp[v][n] + helper(n-1,nxt)) % mod;
        }
        return dp[v][n];
    }
public:
    int countVowelPermutation(int n) {
        memset(dp,-1,sizeof(dp));
        int res = 0;
        for(int i = 0; i < 5; i++) {
            res = (res + helper(n-1,i)) % mod;
        }
        return res;
    }
};