class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int profit = 0, n = prices.size(), sellMax = 0, sell;
        for(int i = n - 1; i >= 0; i--) {
            sell = sellMax;
            sellMax = max(sellMax, profit + prices[i] - fee);
            profit = max(profit, sell - prices[i]);
        }
        
        return profit;
    }
};