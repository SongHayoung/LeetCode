class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int l = 1, r = nums.size() - 2, n = nums.size();
        if(nums[0] > nums[1]) return 0;
        if(nums[n-1] > nums[n-2]) return n - 1;
        while(l <= r) {
            int m = l + (r - l) / 2;
            if(nums[m] > nums[m - 1] and nums[m] > nums[m+1]) return m;
            if(nums[m] < nums[m-1]) r = m - 1;
            else l = m + 1;
        }
        return -1;
    }
};