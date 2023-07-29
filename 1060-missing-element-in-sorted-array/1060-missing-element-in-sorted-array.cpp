class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while(l < r) {
            int m = l + (r - l) / 2;
            int alpha = nums[m] - (m + nums[0]); //how many skips
            if(alpha < k) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        int diff = nums[l] - (l + nums[0]) - k;
        
        if(diff >= 0) return nums[l] - diff - 1;
        return nums[l] - diff;
    }
};