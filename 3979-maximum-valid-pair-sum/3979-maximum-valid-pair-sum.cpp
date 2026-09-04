class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int res = 0, n = nums.size();
        for(int i = n - k - 1, ma = 0; i >= 0; i--) {
            ma = max(ma, nums[i+k]);
            res = max(res, nums[i] + ma);
        }
        return res;
    }
};