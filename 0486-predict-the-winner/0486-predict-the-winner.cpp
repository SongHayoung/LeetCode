class Solution {
    int dp[21][21];
    int helper(vector<int>& nums, int l, int r, bool turn) {
        if(l == r) {
            return turn ? nums[l] : -nums[l];
        }
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        if(turn) {
            dp[l][r] = max(helper(nums, l + 1, r, !turn) + nums[l], helper(nums,l, r - 1, !turn) + nums[r]);
        } else {
            dp[l][r] = min(helper(nums, l + 1, r, !turn) - nums[l], helper(nums,l, r - 1, !turn) - nums[r]);
        }
        return dp[l][r];
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return helper(nums,0,nums.size() - 1, true) >= 0;
    }
};