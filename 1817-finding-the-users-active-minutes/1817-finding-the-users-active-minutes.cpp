class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;
        for(auto& log : logs) {
            int id = log[0], time = log[1];
            mp[id].insert(time);
        }
        vector<int> res(k);
        for(auto& [_, us] : mp) res[us.size() - 1] += 1;
        return res;
    }
};