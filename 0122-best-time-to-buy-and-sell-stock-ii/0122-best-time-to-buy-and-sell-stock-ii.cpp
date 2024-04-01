class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profit(n);
        vector<int> buy(n, INT_MIN);
        buy[0] = -prices[0];
        for(int i = 1; i < prices.size(); i++) {
            buy[i] = max(profit[i-1] - prices[i], buy[i-1]);
            profit[i] = max(profit[i-1], buy[i-1] + prices[i]);
        }
        return profit[n-1];
    }
};