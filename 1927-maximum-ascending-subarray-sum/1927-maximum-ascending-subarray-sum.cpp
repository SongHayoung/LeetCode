class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int res = nums[0], now = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i-1]) now += nums[i];
            else now = nums[i];
            res = max(res, now);
        }
        return res;
    }
};