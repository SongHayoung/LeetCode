class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ok = 0;
        for(int i = 1; i < nums.size() and ok < 2; i++) {
            if(nums[i] < nums[i-1]) {
                ok++;
                if(i == 1 or nums[i-2] <= nums[i]) {
                    nums[i-1] = nums[i];
                } else nums[i] = nums[i-1];
            }
        }
        return ok < 2;
    }
};