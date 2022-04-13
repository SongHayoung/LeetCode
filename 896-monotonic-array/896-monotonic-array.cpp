class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) continue;
            else if(nums[i] > nums[i+1]) {
                if(inc == -1) return false;
                inc = 1;
            } else {
                if(inc == 1) return false;
                inc = -1;
            }
        }
        return true;
    }
};