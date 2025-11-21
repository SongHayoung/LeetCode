class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        return nums[n-1] + nums[n-2] - nums[0];
    }
};