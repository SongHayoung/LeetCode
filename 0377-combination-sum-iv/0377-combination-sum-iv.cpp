class Solution {
    int dp[1001];
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp, -1, sizeof(dp));
        dp[0] = 1;
        sort(nums.begin(), nums.end());
        return dfs(nums, target);
    }

    int dfs(vector<int>& nums, int target) {
        if(dp[target] != -1) return dp[target];
        dp[target] = 0;
        for(int i = 0; i < nums.size() and nums[i] <= target; i++)
            dp[target] += dfs(nums,target - nums[i]);
        return dp[target];
    }
};