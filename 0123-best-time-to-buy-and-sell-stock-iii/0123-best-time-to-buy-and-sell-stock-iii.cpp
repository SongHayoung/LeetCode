class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int cheapBuy = INT_MAX;
        int sellOnce = 0;
        int buyTwice = INT_MIN;
        for(auto& p : prices) {
            res = max(res, buyTwice + p);
            buyTwice = max(buyTwice, sellOnce - p);
            sellOnce = max(sellOnce, p - cheapBuy);
            cheapBuy = min(cheapBuy, p);
        }
        return res;
    }
};