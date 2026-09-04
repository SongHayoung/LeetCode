class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        vector<long long> pre{0}, pos{0};
        long long res = LLONG_MIN, n = prices.size();
        for(int i = 0; i < n; i++) {
            pre.push_back(pre.back() + prices[i] * strategy[i]);
            pos.push_back(pos.back() + prices[i]);
        }
        for(int i = 0; i <= n - k; i++) {
            long long now = pre[i] + pre[n] - pre[i+k] + pos[i+k] - pos[i + k / 2];
            res = max(res, now);
        }
        res = max(res, pre.back());
        return res;
    }
};
