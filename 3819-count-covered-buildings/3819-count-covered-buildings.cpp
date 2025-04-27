class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,pair<int,int>> ymp, xmp;
        auto push = [](unordered_map<int,pair<int,int>>& mp, int key, int val) {
            if(!mp.count(key)) mp[key] = {val, val};
            else {
                mp[key].first = min(mp[key].first, val);
                mp[key].second = max(mp[key].second, val);
            }
        };
        for(auto& b : buildings) {
            int y = b[0], x = b[1];
            push(ymp, y, x);
            push(xmp, x, y);
        }
        int res = 0;
        auto ok = [](unordered_map<int,pair<int,int>>& mp, int key, int val) {
            auto [l,r] = mp[key];
            return l < val and val < r;
        };
        for(auto& b : buildings) {
            int y = b[0], x = b[1];
            res += ok(ymp, y, x) and ok(xmp, x, y);
        }
        return res;
    }
};
