class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIdx = 0;
        for(int i = 0; i <= maxIdx and i < nums.size() and maxIdx <= nums.size(); i++) {
            maxIdx = max(maxIdx, i + nums[i]);
        }
        return maxIdx >= nums.size() - 1;
    }
};