class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        nums.push_back(lower-1);
        nums.push_back(upper+1);
        sort(begin(nums), end(nums));
        vector<vector<int>> res;
        for(int i = 0; i < nums.size() - 1; i++) {
            int l = nums[i] + 1, r = nums[i+1] - 1;
            if(l <= r and l >= lower and r <= upper) res.push_back({l,r});
        }
        return res;
    }
};