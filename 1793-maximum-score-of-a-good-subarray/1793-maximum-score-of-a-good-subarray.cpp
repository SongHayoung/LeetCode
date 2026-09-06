class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], n = nums.size(), l = k, r = k, mi = nums[k];
        while(!(l == 0 and r == n - 1)) {
            if(l > 0 and r < n - 1) {
                if(nums[l-1] >= nums[r+1]) {
                    l--;
                    mi = min(mi,nums[l]);
                } else {
                    r++;
                    mi = min(mi, nums[r]);
                }
            } else if(l > 0) {
                l--;
                mi = min(mi,nums[l]);
            } else { // r
                r++;
                mi = min(mi, nums[r]);
            }





            res = max(res, (r - l + 1) * mi);
        }
        return res;
    }
};