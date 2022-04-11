class Solution {
    vector<vector<int>> res;
    void backTracking(vector<int>& c, vector<int>& nums, int i, int sum, int target) {
        if(sum == target) {
            res.push_back(nums);
            return;
        } else if(sum > target) return;
        
        for(int index = i; index < c.size() and sum + c[index] <= target; index++) {
            nums.push_back(c[index]);
            backTracking(c,nums,index,sum + c[index], target);
            nums.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> num;
        backTracking(candidates, num, 0, 0, target);
        return res;
    }
};