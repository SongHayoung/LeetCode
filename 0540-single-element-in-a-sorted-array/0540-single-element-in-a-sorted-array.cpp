class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            if(m & 1) { //odd
                if(nums[m-1] == nums[m]) l = m + 1;
                else {
                    if(m + 1 == nums.size() or nums[m+1] != nums[m]) return nums[m];
                    r = m - 1;
                }
            } else {
                if(nums[m+1] == nums[m]) l = m + 1;
                else {
                    if(m - 1 < 0 or nums[m-1] != nums[m]) return nums[m];
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};