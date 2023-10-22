class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int res = nums[k], l = k, r = k, n = nums.size(), mi = nums[k];
        while(nums.size() != 1) {
            if(l != 0 and nums[l-1] >= mi) l--;
            else if(r != n - 1 and nums[r + 1] >= mi) r++;
            else if(l != 0 and r != n - 1) {
                if(nums[l-1] >= nums[r+1]) l--;
                else r++;
            } else if(l == 0) r++;
            else l--;
            
            mi = min({mi, nums[l], nums[r]});
            res = max(res, mi * (r - l + 1));
            
            if(l == 0 and r == n - 1) break;
        }
        return res;
    }
};