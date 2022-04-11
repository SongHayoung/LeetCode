class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int check(0);
        for(int i = 1; i < nums.size() and check < 2; ++i) {
            if(nums[i - 1] > nums[i]) {
                ++check;
                (i < 2 or nums[i - 2] <= nums[i]) ? (nums[i - 1] = nums[i]) : (nums[i] = nums[i - 1]);
            }
        }
        return check < 2;
    }
};