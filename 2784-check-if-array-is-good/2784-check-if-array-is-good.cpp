class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(begin(nums), end(nums));
        if(nums.size() == 1) return false;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] != i + 1) return false;
        }
        if(nums.back() != nums[nums.size() - 2]) return false;
        return true;
    }
};