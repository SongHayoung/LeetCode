class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(auto n : nums) {
            int index = abs(n) - 1;
            if(nums[index] < 0) return abs(n);
            nums[index] = -nums[index];
        }
        return -1;
    }
};