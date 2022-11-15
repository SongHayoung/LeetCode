class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        int res = -1;
        sort(begin(nums), end(nums));
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            if(nums[l] + nums[r] < k) res = max(res, nums[l++] + nums[r]);
            else r--;
        }
        return res;
    }
};