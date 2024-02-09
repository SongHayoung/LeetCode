class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        vector<int> ok(nums.size());
        ok[0] = true;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] >= nums[i]) break;
            ok[i] = true;
        }
        if(ok.back()) return true;
        if(ok[nums.size()-2]) return true;
        for(int i = nums.size() - 1; i >= 1; i--) {
            if(nums[i-1] >= nums[i]) {
                if(i == 1) return true;
                if(!ok[i-2]) return false;
                return nums[i-2] < nums[i];
            }
            if(i >= 2 and nums[i-2] < nums[i] and ok[i-2]) return true;
        }
        return false;
    }
};