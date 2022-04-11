class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<int> dp(p.size());
        int mi = p[0], ma = p.back(), n = p.size(), res = 0;
        for(int i = 1; i < n; i++) {
            dp[i] = max(p[i] - mi, dp[i-1]);
            mi = min(mi, p[i]);
        }
        res = dp.back();
        for(int i = n - 2; i > 0; i--) {
            res = max({res, dp[i-1] + ma - p[i], dp[i]});
            ma = max(ma, p[i]);
        }
        return res;
    }
};