class Solution {
public:
    int maxSum(vector<int>& nums, int k, int m) {
        vector<vector<long long>> dp(k, vector<long long>(m+1, INT_MIN));
        dp[0][0] = 0;
        long long res = INT_MIN;
        for(auto& x : nums) {
            for(int i = k - 1; i >= 0; i--) {
                if(i) dp[i][0] = max(dp[i][0], dp[i-1][m]);
                dp[i][m] = max({dp[i][m] + x, dp[i][m-1] + x});
                for(int j = m - 1; j; j--) {
                    dp[i][j] = dp[i][j-1] + x;
                }
            }
            res = max(res, dp[k-1][m]);
        }
        return res;
    }
};