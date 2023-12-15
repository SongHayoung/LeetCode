class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> ind, oud;
        for(auto p : paths) {
            auto src = p[0], dst = p[1];
            ind.insert(src);
            oud.insert(dst);
        }
        for(auto& o : oud) {
            if(!ind.count(o)) return o;
        }
        return "";
    }
};