class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return nums[0] == target;
        if(nums[0] == target)
            return true;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] < nums[i - 1]) {
                if(nums[0] < target)
                    return false;
                auto it = lower_bound(nums.begin() + i, nums.end(), target);
                return it != end(nums) && *it == target;
            } else if(nums[i] == target)
                return true;
        }
        return false;
    }
};
