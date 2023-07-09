class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        vector<long long> res(nums.size(), INT_MIN);
        res[0] = 0;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                if(-target <= nums[j] - nums[i] and nums[j] - nums[i] <= target) {
                    res[j] = max(res[j], res[i] + 1);
                }
            }
        }
        if(res.back() <= 0) return -1;
        return res.back();
    }
};