class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pos = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[pos-1]) continue;
            nums[pos++] = nums[i];
        }
        return pos;
    }
};