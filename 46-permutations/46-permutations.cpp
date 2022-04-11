class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        do {
            res.push_back(nums);
        } while(next_permutation(begin(nums), end(nums)));
        return res;
    }
};