class Solution {
public:
    int findMin(vector<int>& nums) {
        int res = nums[0], l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] >= res) {
                l = m + 1;
            } else {
                r = m - 1;
                res = nums[m];
            }
        }
        return res;
    }
};