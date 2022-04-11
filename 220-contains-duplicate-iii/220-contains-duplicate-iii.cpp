class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        multiset<int> sets;
        for(int i = 0; i < nums.size(); i++) {
            auto it = sets.insert(nums[i]);
            auto lower = it, upper = ++it;
            if((lower != sets.begin() && *(--lower) >= (INT_MIN + t > nums[i] ? INT_MIN : nums[i] - t)) ||
                    (upper != sets.end() && *upper <= (INT_MAX - t < nums[i] ? INT_MAX : nums[i] + t)))
                return true;
            if(i >= k)
                sets.erase(nums[i - k]);
        }

        return false;
    }
};