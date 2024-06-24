class Solution {
    int fliped(vector<int>& dp, int i, int k) {
        if(i < k) return 0;
        return dp[i-k];
    }
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(), flip = 0;
        vector<int> dp(n - k + 1,0);
        for(int i = 0; i <= n - k; i++) {
            if(nums[i] == 0) {
                if((flip - fliped(dp,i,k)) & 1)  {
                    dp[i] = flip;
                } else dp[i] = ++flip;
            } else {
                if((flip - fliped(dp,i,k)) & 1)  {
                    dp[i] = ++flip;
                } else dp[i] = flip;
            }
        }
        for(int i = n - k + 1; i < n; i++) {
            if(nums[i] == 0) {
                if(!((flip - fliped(dp,i,k)) & 1)) return -1;
            } else {
                if((flip - fliped(dp,i,k)) & 1)  return -1;
            }
        }
        return flip;
    }
};