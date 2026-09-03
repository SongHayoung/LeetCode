
class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        sort(rbegin(discounts), rend(discounts));
        sort(rbegin(prices), rend(prices));
        long double res = 0.;
        for(int i = 0; i < prices.size(); i++) {
            if(discounts.size() > i) {
                res += 1. * prices[i] * (100 - discounts[i]) / 100;
            } else res += prices[i];
        }
        return res;
    }
};