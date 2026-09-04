
int dp[101010][2][2];
class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        memset(dp,0,sizeof dp);
        for(int i = 0; i < n; i++) {
            dp[i][0][0] = dp[i][0][1] = 1;
            if(i and nums[i-1] < nums[i]) dp[i][0][1] = dp[i-1][0][0] + 1;
            if(i and nums[i-1] > nums[i]) dp[i][0][0] = dp[i-1][0][1] + 1;
        }
        for(int i = n - 1; i >= 0; i--) {
            dp[i][1][0] = dp[i][1][1] = 1;
            if(i + 1 < n and nums[i] < nums[i+1]) dp[i][1][1] = dp[i+1][1][0] + 1;
            if(i + 1 < n and nums[i] > nums[i+1]) dp[i][1][0] = dp[i+1][1][1] + 1;
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max({res, dp[i][0][0],dp[i][0][1],dp[i][1][0],dp[i][1][1]});
            if(i and i + 1 < n) {
                if(nums[i-1] < nums[i+1]) {
                    res = max(res, dp[i-1][0][0] + dp[i+1][1][0]);
                }
                if(nums[i-1] > nums[i+1]) {
                    res = max(res, dp[i-1][0][1] + dp[i+1][1][1]);
                }
            }
        }
        return res;
    }
};
