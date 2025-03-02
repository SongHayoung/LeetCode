class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> mp;
        for(auto n : nums1) {
            int id = n[0], val = n[1];
            mp[id] += val;
        }
        for(auto n : nums2) {
            int id = n[0], val = n[1];
            mp[id] += val;
        }
        vector<vector<int>> res;
        for(auto [k,v] : mp) res.push_back({k,v});
        return res;
    }
};