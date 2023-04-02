class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++) {
            int idx = mp[nums[i]];
            if(res.size() == idx) res.emplace_back();
            res[idx].push_back(nums[i]);
            mp[nums[i]] += 1;
        }
        return res;
    }
};