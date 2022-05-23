class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k, l, n = nums.size();
        for(k = n - 2; k >= 0; k--) {
            if(nums[k] < nums[k + 1]) break;
        }
        if(k < 0) {
            reverse(begin(nums), end(nums));
            return;
        }
        
        for(l = n - 1; l > k; l--) {
            if(nums[l] > nums[k]) break;
        }
        swap(nums[l], nums[k]);
        sort(begin(nums) + k + 1, end(nums));
    }
};