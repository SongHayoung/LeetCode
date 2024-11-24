class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX, n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i, sum = 0; j < n and j < i + r; j++) {
                sum += nums[j];
                if(sum > 0 and j >= i + l - 1) {
                    res = min(res, sum);
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};