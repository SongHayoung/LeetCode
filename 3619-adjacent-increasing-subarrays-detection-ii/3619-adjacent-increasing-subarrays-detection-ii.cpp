class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        vector<int> dp(nums.size());
        int res = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!i or nums[i] <= nums[i-1]) dp[i] = 1;
            else dp[i] = dp[i-1] + 1;
            res = max(res, dp[i] / 2);
            if(i - dp[i] >= 0) res = max(res, min(dp[i-dp[i]], dp[i]));
        }
        return res;
    }
};