class Solution {
    int dp[5001][2];
    int dfs(vector<int>& prices, int i, bool hasStock) {
        if(i >= prices.size()) return 0;
        if(dp[i][hasStock] != -1) return dp[i][hasStock];
        return dp[i][hasStock] = max(dfs(prices, i + 1, hasStock), dfs(prices, i + (hasStock ? 2 : 1), !hasStock) + (hasStock ? prices[i] : -prices[i]));
    }
public:
    int maxProfit(vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return dfs(prices, 0, false);
    }
};