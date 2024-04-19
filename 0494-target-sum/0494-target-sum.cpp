class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < target) return 0;
        int x = sum - target;
        if(x & 1) return 0;
        x /= 2;
        vector<int> dp(x + 1);
        dp[0] = 1;
        for(auto& n : nums) {
            for(int i = x - n; i >= 0; i--) {
                dp[i+n] += dp[i];
            }
        }
        
        return dp.back();
    }
};