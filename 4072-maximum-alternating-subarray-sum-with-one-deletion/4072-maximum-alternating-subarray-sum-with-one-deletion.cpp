class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long neg = -1e18;
        long long dp[2][2] = {
            {neg, neg},
            {neg, neg}
        };
        long long res = neg;

        for(long long x : nums) {
            long long ndp[2][2] = {
                {max(0ll, dp[0][1]) + x, dp[0][0] - x},
                {max(dp[1][1] + x, dp[0][0]), max(dp[1][0] - x, dp[0][1])}
            };

            swap(dp,ndp);
            res = max({res,dp[0][0],dp[0][1],dp[1][0],dp[1][1]});
        }

        return res;
    }
};