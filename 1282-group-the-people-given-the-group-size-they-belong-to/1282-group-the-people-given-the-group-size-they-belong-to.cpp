class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> lookup;
        vector<vector<int>> res;
        for(int i = 0; i < groupSizes.size(); i++) {
            int sz = groupSizes[i];
            lookup[sz].push_back(i);
            if(lookup[sz].size() == sz) {
                res.push_back(lookup[sz]);
                lookup[sz].clear();
            }
        }
        return res;
    }
};