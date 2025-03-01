class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        assert(1 <= nums.size() and nums.size() <= 100);
        for(int i = nums.size() - 1, odd = nums.size() - 1; i >= 0; i--) {
            assert(1 <= nums[i] and nums[i] <= 1000);
            if(nums[i] &= 1) swap(nums[i], nums[odd--]);
        }
        return nums;
    }
};