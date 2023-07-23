class Solution {
public:
    long long maxScore(vector<int>& nums, int x) {
        long long dp1 = nums[0] & 1 ? INT_MIN : nums[0], dp2 = nums[0] & 1 ? nums[0] : INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] & 1) {
                dp2 = max(dp2 + nums[i], dp1 + nums[i] - x);
            } else {
                dp1 = max(dp1 + nums[i], dp2 + nums[i] - x);
            }
        }
        return max(dp1, dp2);
    }
};