class Solution {
public:
    long long maximumStrength(vector<int>& nums, int k) {
        vector<long long> dp(k,-1e18);
        long long res = -1e18;
        for(int i = 0; i < nums.size(); i++) {
            long long x = nums[i];
            for(long long j = k - 1; j >= 1; j--) {
                long long mul = k - j, sign = mul & 1 ? 1 : -1;
                mul = mul * sign * x;
                dp[j] = max(dp[j] + mul, dp[j-1] + mul);
            }
            dp[0] = max(dp[0] + x * k, x * k);
            res = max(res, dp.back());
        }

        return res;
    }
};