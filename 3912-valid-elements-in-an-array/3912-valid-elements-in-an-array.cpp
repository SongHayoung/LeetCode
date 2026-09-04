class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<bool> ok(nums.size());
        for(int i = 0, ma = 0; i < nums.size(); i++) {
            if(nums[i] > ma) ok[i] = true;
            ma = max(ma, nums[i]);
        }
        for(int i = nums.size() - 1, ma = 0; i >= 0; i--) {
            if(nums[i] > ma) ok[i] = true;
            ma = max(ma, nums[i]);
        }
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) if(ok[i]) res.push_back(nums[i]);
        return res;
    }
};