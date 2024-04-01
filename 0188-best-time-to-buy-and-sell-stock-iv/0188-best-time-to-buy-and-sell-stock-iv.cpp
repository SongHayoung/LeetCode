class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<pair<int,int>> dp(k + 1, {0,INT_MIN});
        for(auto& p : prices) {
            for(int i = k; i >= 1; i--) {
                dp[i].second = max(dp[i].second, dp[i].first - p);
                dp[i].first = max(dp[i-1].second + p, dp[i].first);
            }
            dp[0].second = max(dp[0].second, -p);
        }
        int res = 0;
        for(auto& [profit, buy] : dp) res = max(res, profit);
        return res;
    }
};