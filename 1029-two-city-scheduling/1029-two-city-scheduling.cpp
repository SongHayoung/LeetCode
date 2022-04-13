class Solution {
    int dp[101][101];
    int helper(vector<vector<int>>& c, int i, int n) {
        if(i == c.size()) return 0;
        if(dp[i][n] != -1) return dp[i][n];
        dp[i][n] = INT_MAX;
        if(n != 0)
            dp[i][n] = min(dp[i][n], c[i][0] + helper(c,i+1,n-1));
        if(n + i != c.size())
            dp[i][n] = min(dp[i][n], c[i][1] + helper(c,i+1,n));
        return dp[i][n];
    }
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        memset(dp,-1,sizeof(dp));
        return helper(costs,0,costs.size() / 2);
    }
};