class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {
        long long dp0 = LLONG_MIN, dp1 = LLONG_MIN, dp2 = LLONG_MIN, res = LLONG_MIN;
        for(int i = b.size() - 1; i >= 0; i--) {
            if(dp0 != LLONG_MIN) res = max(res, dp0 + 1ll * a[0] * b[i]);
            if(dp1 != LLONG_MIN) dp0 = max(dp0, dp1 + 1ll * a[1] * b[i]);
            if(dp2 != LLONG_MIN) dp1 = max(dp1, dp2 + 1ll * a[2] * b[i]);
            dp2 = max(dp2, 1ll * a[3] * b[i]);
        }
        return res;
    }
};