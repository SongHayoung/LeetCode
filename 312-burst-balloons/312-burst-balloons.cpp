class Solution {
    vector<vector<int>> dp;
    int helper(vector<int>& nums, int l, int r) {
        if(l + 1 == r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        for(int i = l + 1; i < r; i++) {
            dp[l][r] = max(
                dp[l][r],
                nums[l] * nums[i] * nums[r] +
                helper(nums,l,i) + helper(nums,i,r));
        }
        return dp[l][r];
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> nonZeroNums(nums.size() + 2);
        int n = 1;
        for(auto num : nums) {
            if(num)
                nonZeroNums[n++] = num;
        }
        nonZeroNums[0] = nonZeroNums[n] = 1;
        dp = vector<vector<int>>(n + 1, vector<int>(n + 1, -1));
        return helper(nonZeroNums, 0, n);
    }
};