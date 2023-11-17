class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() / 2; i++) {
            res = max(res, nums[i] + nums[nums.size() - 1 - i]);
        }
        return res;
    }
};