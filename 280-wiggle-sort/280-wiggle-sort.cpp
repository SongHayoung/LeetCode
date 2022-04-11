class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for(int i = 0; i < nums.size() - 1; i++) {
            if(i & 1 and nums[i] < nums[i+1]) swap(nums[i],nums[i+1]);
            else if(!(i&1) and nums[i] > nums[i+1]) swap(nums[i], nums[i+1]);
        }
    }
};