class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto st = lower_bound(nums.begin(), nums.end(), target);
        if(st == end(nums) or *st != target) return false;
        auto ed = upper_bound(nums.begin(), nums.end(), target);
        auto cnt = ed - st;
        return nums.size() < cnt * 2;
        
    }
};