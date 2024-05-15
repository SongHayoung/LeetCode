class Solution {
public:
    int maxProfit(vector<int>& prices) {
        pair<int, int> dp{0,INT_MIN};
        for(auto& p : prices) {
            pair<int, int> dpp = dp;
            dp.first = max(dpp.first, dpp.second + p);
            dp.second = max(dpp.second, dp.first - p);
        }
        return dp.first;
    }
};