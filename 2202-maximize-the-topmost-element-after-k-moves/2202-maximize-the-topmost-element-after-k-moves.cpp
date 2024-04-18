class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        if(!k) return nums[0];
        if(k == 1) return nums.size() == 1 ? -1 : nums[1];
        if(nums.size() == 1) return k & 1 ? -1 : nums[0];
        if(k == nums.size()) return *max_element(begin(nums), prev(end(nums)));
        if(k > nums.size()) return *max_element(begin(nums), end(nums));
        int best = 0;
        for(int i = 0; i < k - 1; i++) best = max(best, nums[i]);
        return max(best, nums[k]);
    }
};