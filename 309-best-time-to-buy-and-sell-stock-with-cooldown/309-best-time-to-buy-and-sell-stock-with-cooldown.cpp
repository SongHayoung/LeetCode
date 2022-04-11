class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), res = 0;
        int coolDownProfit = 0, prevProfit = 0, sellMax = 0;
        for(int i = n - 1; i >= 0; i--) {
            int tmp = prevProfit;
            prevProfit = max(prevProfit, sellMax - prices[i]);
            sellMax = max(sellMax, coolDownProfit + prices[i]);
            res = max(res, prevProfit);
            coolDownProfit = tmp;
        }
        return res;
    }
};