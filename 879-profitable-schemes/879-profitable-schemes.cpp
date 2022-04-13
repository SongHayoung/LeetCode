class Solution {
    int dp[101][101][101];
    int mod = 1e9 + 7;
    int helper(int index, int n, int mp, vector<int>& g, vector<int>& p) {
        if(index == g.size()) return mp == 0;
        int& res = dp[index][n][mp];
        if(res != -1) return res;
        res = helper(index + 1, n, mp, g, p);
        if(g[index] <= n)
            res = (res + helper(index + 1, n - g[index], max(0,mp - p[index]), g, p)) % mod;
        return res;
    }
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return helper(0,n,minProfit,group,profit);
    }
};