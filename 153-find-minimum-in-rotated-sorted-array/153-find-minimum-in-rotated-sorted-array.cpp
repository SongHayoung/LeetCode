class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l <= r) {
            int m = l + (r-l)/2;
            int L = m - 1 >= 0 ? nums[m-1] : INT_MAX;
            int R = m + 1 < nums.size() ? nums[m+1] : INT_MAX;
            if(L >= nums[m] and nums[m] <= R) return nums[m];
            else if(nums[m] < nums[r])
                r = m - 1;
            else l = m + 1;
        }
        return INT_MIN;
    }
};