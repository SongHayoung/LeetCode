class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<long long> dp(target + 1, INT_MIN);
        dp[0] = 0;
        for(auto n : nums) {
            for(int j = target - n; j >= 0; j--) {
                dp[j+n] = max(dp[j+n], dp[j] + 1);
            }
        }
        if(dp[target] > 0) return dp[target];
        return -1;
    }
};
