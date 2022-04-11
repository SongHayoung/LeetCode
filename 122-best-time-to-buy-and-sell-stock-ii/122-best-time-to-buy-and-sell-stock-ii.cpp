class Solution {
public:
    int maxProfit(vector<int>& p) {
        int res = 0;
        for(int buy = 0; buy < p.size();) {
            int sell = buy + 1;
            for(; sell < p.size() and p[sell] >= p[sell - 1]; sell++) {}
            res += max(0, p[sell-1] - p[buy]);
            buy = sell;
        }
        return res;
    }
};