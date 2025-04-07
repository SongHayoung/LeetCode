class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        
        vector<bool> dp(sum/2 + 1, 0);
        dp[0] = true;
        for(auto n : nums) {
            for(int i = sum/2 + 1; i >= n; i--) {
                dp[i] = dp[i] | dp[i-n];
            }
        }
        return dp[sum/2];
    }
};