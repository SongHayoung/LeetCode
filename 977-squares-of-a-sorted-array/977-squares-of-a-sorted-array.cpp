class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        int l = 0, r = nums.size() - 1, i = nums.size() - 1;
        while(l <= r) {
            if(abs(nums[l]) > abs(nums[r])) {
                res[i--] = (nums[l] * nums[l++]);
            } else {
                res[i--] = (nums[r] * nums[r--]);
            }
        }
        return res;
    }
};