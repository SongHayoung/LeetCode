class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        sort(begin(logs), end(logs), [](auto a, auto b) {
            return a[1] < b[1];
        });
        unordered_map<int, int> mp;
        for(int i = 0; i < logs.size();) {
            int j = i;
            unordered_set<int> us;
            while(j < logs.size() and logs[j][1] == logs[i][1]) {
                us.insert(logs[j][0]);
                j++;
            }
            i = j;
            for(auto& u : us) ++mp[u];
        }
        vector<int> res(k);
        for(auto& [_,v] : mp) res[v-1]++;
        return res;
    }
};