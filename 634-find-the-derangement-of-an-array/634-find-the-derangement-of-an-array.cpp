class Solution {
public:
    int findDerangement(int n) {
        long dp1 = 0, dp2 = 1, res = n - 1, mod = 1e9 + 7;
        for(int i = 3; i <= n; i++, dp1 = dp2, dp2 = res) {
            res = (i - 1) * (dp2 + dp1) % mod;
        }
        return res;
    }
};