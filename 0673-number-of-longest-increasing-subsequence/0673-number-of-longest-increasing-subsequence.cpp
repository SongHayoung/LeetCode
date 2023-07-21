class Solution {
    vector<vector<int>> dp;
    int LIS(vector<int>& nums) {
        vector<int> lis;
        for(auto& n : nums) {
            if(lis.empty() or lis.back() < n) {
                lis.push_back(n);
            } else {
                auto p = lower_bound(lis.begin(),lis.end(),n);
                *p = n;
            }
        }
        return lis.size();
    }
    int helper(vector<int>& nums, int p, int k) {
        if(k == 0) return 1;
        if(p == nums.size()) return 0;
        if(dp[p][k] != -1) return dp[p][k];
        dp[p][k] = 0;
        for(int i = p + 1; i <= nums.size() - k; i++) {
            if(nums[p] < nums[i])
                dp[p][k] += helper(nums,i,k-1);
        }
        return dp[p][k];
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        int len = LIS(nums), n = nums.size(), res = 0;
        dp = vector<vector<int>>(n, vector<int>(len, -1));
        for(int i = 0; i <= nums.size() - len; i++)
            res += helper(nums,i,len - 1);
        return res;
    }
};