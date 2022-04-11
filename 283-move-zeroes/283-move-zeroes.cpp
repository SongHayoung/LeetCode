class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero = 0, nonZero = 0, n = nums.size();
        for(int i = 0; i < n and (nums[zero] or !nums[nonZero] or nonZero < zero); i++) {
            if(nums[zero]) ++zero;
            if(!nums[nonZero] or nonZero < zero) ++nonZero;
        }
        while(zero < n and nonZero < n) {
            if(nonZero > zero) swap(nums[zero], nums[nonZero]);
            while(nonZero < n and (!nums[nonZero] or nonZero < zero)) ++nonZero;
            while(zero < n and nums[zero]) ++zero;
        }
    }
};