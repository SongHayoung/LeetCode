class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0;
        for(int i = 0; i < nums.size() and i <= jump; i++) {
            jump = max(jump, i + nums[i]);
        }
        return jump >= nums.size() - 1;
    }
};