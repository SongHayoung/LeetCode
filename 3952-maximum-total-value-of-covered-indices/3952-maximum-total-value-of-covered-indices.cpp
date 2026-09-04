class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        long long n = nums.size();
        vector<vector<long long>> dp(2, vector<long long>(n));
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                if(!i) dp[1][i] = nums[i];
                else {
                    dp[1][i] = max(max(dp[0][i-1],dp[1][i-1]) + nums[i], dp[0][i-1] + nums[i-1]);
                    dp[0][i] = dp[0][i-1] + nums[i-1];
                }
            } else {
                if(i) dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            }
        }
        return max(dp[0].back(), dp[1].back());
    }
};