class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        nums.erase(unique(begin(nums), end(nums)), end(nums));
        reverse(begin(nums), end(nums));
        while(nums.size() > k) nums.pop_back();
        return nums;
    }
};
