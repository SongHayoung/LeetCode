class Solution {
    int getOrDefault(vector<int>& nums, int i, int def = INT_MIN) {
        if(i < 0 or i >= nums.size())
            return def;
        return nums[i];
    }
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            int left = getOrDefault(nums, m - 1);
            int right = getOrDefault(nums, m + 1);
            if(nums[m] > left and nums[m] > right) return m;
            else if(left > right) r = m - 1;
            else l = m + 1;
        }
        return l;
    }
};