class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets{{}};
        for(auto& n : nums) {
            int sz = subsets.size();
            for(int i = 0; i < sz; i++) {
                vector<int> s = subsets[i];
                s.push_back(n);
                subsets.push_back(s);
            }
        }
        set<vector<int>> s(subsets.begin(), subsets.end());
        return vector<vector<int>>(s.begin(), s.end());
    }
};