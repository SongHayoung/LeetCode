class Solution {
public:
    int maxProfit(vector<int>& A) {
        long long dp1 = INT_MIN, dp2 = INT_MIN, dp3 = INT_MIN, res = 0;
        for(auto& a : A) {
            res = max({res, dp1 + a, dp3 + a});
            dp3 = max(dp3, dp2 - a);
            dp2 = max(dp2, dp1 + a);
            dp1 = max(dp1, -1ll * a);
        }
        return res;
    }
};