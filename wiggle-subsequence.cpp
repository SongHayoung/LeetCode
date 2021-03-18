class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)
            return 1;
        pair<int, int> lower{1,nums[0]}, upper{1,nums[0]};

        for(int i = 1; i < nums.size(); i++) {
            pair<int, int> l = lower, u = upper;
            if(lower.second > nums[i]) {
                u = upper.first < lower.first + 1 ?
                        make_pair(lower.first + 1, nums[i]) : upper.first == lower.first + 1 ? upper.second > nums[i] ? make_pair(lower.first + 1, nums[i]) : upper : upper;
            }
            if(upper.second < nums[i]) {
                l = lower.first < upper.first + 1 ?
                        make_pair(upper.first + 1, nums[i]) : lower.first == upper.first + 1 ? lower.second < nums[i] ? make_pair(upper.first + 1, nums[i]) : lower : lower;
            }
            lower = l, upper = u;
        }

        return max(lower.first, upper.first);
    }
};
