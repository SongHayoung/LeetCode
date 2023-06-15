class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        nums.push_back(INT_MAX);
        nums.push_back(INT_MIN);
        sort(begin(nums),end(nums));
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 1; i++) {
            int le = max(lower, nums[i] + 1), ri = min(upper,nums[i+1] - 1);
            if(le > ri) continue;
            res.push_back({le,ri});
        }
        return res;
    }
};