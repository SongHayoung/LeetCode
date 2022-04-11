class Solution {
    int dp[1001][2];
    int solution(vector<int>& nums, int p, bool upper) {
        if(p == nums.size()) return 0;
        if(dp[p][upper] != -1) return dp[p][upper];
        dp[p][upper] = 1;
        for(int i = p + 1; i < nums.size(); i++) {
            if((upper and nums[i] > nums[p]) or (!upper and nums[i] < nums[p])) {
                dp[p][upper] = max(dp[p][upper], solution(nums, i, !upper) + 1);
            }
        }
        
        return dp[p][upper];
    }
public:
    int wiggleMaxLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        
        return max(solution(nums,0,true), solution(nums,0,false));
    }
};