class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        int pos = 2;
        for(int i = 2; i < nums.size(); i++) {
            if(nums[i] == nums[pos-1] && nums[i] == nums[pos-2]) continue;
            nums[pos++] = nums[i];
        }
        return pos;
    }
};