class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(begin(prices), end(prices));
        int res = money - prices[0] - prices[1];
        return res >= 0 ? res : money;
    }
};
