class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int res = 1e9, n = nums.size();
        for(int i = 1; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                res = min(res, nums[0] + nums[i] + nums[j]);
            }
        }
        return res;
    }
};