class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        sort(begin(nums), end(nums));
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == nums[0] or nums[i] == nums.back()) continue;
            return nums[i];
        }
        return -1;
    }
};
