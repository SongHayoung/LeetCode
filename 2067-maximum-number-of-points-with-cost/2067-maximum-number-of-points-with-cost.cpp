class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points[0].size();
        vector<long long> dp(m, 0), prv(m, 0);
        for(auto& r : points) {
            for(long long i = 0, ma = INT_MIN; i < m; i++) {
                dp[i] = ma = max(ma - 1, prv[i]);
            }
            for(long long i = m - 1, ma = INT_MIN; i >= 0; i--) {
                dp[i] = ma = max(ma - 1, dp[i]);
                dp[i] += r[i];
            }
            swap(dp, prv);
        }
        return *max_element(begin(prv),end(prv));
    }
};