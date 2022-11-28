class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> mp;
        for(auto& m : matches) {
            mp[m[1]]++;
            mp[m[0]] += 0;
        }
        vector<vector<int>> res(2);
        
        for(auto [p, l] : mp) {
            if(l == 0) res[0].push_back(p);
            else if(l == 1) res[1].push_back(p);
        }
        
        sort(res[0].begin(), res[0].end());
        sort(res[1].begin(), res[1].end());
        return res;
    }
};