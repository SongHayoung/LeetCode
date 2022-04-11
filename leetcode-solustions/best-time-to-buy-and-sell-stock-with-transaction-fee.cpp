class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<pair<int, int>> dp(prices.size(), {0, -prices[0]});

        for(int i = 1; i < prices.size(); i++) {
            dp[i] = {max(dp[i - 1].first, dp[i - 1].second + prices[i] - fee),max(dp[i - 1].second, dp[i - 1].first - prices[i])};
        }

        return max(dp[prices.size() - 1].first, dp[prices.size() - 1].second);
    }
};
