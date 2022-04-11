class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 1; i < nums.size(); i++) {
            while(nums[i] < nums[i - 1]) {
                swap(nums[upper_bound(nums.begin(), nums.begin() + i - 1, nums[i]) - nums.begin()], nums[i]);
            }
        }
    }
};
