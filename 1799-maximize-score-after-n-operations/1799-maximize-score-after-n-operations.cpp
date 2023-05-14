class Solution {
    int dp[1<<15];
    int helper(int mask, vector<int>& nums) {
        if(mask == (1<<nums.size()) - 1) return 0;
        if(dp[mask] != -1) return dp[mask];
        int n = nums.size(), count = __builtin_popcount(mask) / 2;
        
        for(int i = 0; i < n; i++) {
            if(mask & 1<<i) continue;
            for(int j = i + 1; j < n; j++) {
                if(mask & 1<<j) continue;
                dp[mask] = max(dp[mask], (count + 1) * __gcd(nums[i], nums[j]) + helper(mask | 1<<i | 1<<j, nums));
            }
        }
        return dp[mask];
    }
public:
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(0, nums);
    }
};