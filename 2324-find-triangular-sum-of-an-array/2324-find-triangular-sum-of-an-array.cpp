class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        for(int ed = n - 1; ed >= 1; ed--) {
            for(int i = 0; i < ed; i++) {
                nums[i] = (nums[i] + nums[i + 1]) % 10;
            }
        }
        
        return nums[0];
    }
};