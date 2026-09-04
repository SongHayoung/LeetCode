class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonNegs;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] >= 0) nonNegs.push_back(i);
        }
        if(nonNegs.size() == 0) return nums;
        k %= nonNegs.size();
        vector<int> res;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] < 0) res.push_back(nums[i]);
            else {
                res.push_back(nums[nonNegs[k % nonNegs.size()]]);
                k++;
            }
        }
        return res;
    }
};