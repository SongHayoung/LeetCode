class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> res(prices.size());
        deque<int> dq;
        for(int i = prices.size() - 1; i >= 0; i--) {
            while(dq.size() and prices[dq.front()] > prices[i]) dq.pop_front();
            res[i] = prices[i] - (dq.size() ? prices[dq.front()] : 0);
            dq.push_front(i);
        }
        return res;
    }
};