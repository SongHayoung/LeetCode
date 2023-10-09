class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        auto startIt = lower_bound(begin(nums), end(nums), target);
        if(startIt == end(nums) || *startIt != target) return {-1, -1};
        auto endIt = prev(upper_bound(begin(nums), end(nums), target));
        
        return {(int)distance(begin(nums), startIt), (int)distance(begin(nums), endIt)};
    }
};
