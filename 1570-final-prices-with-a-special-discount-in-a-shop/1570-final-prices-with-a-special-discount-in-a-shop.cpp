class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> st, res(prices.size());
        for(int i = prices.size() - 1; i >= 0; i--) {
            while(st.size() and prices[st.back()] > prices[i]) st.pop_back();
            res[i] = prices[i] - (st.size() ? prices[st.back()] : 0);
            st.push_back(i);
        }
        return res;
    }
};