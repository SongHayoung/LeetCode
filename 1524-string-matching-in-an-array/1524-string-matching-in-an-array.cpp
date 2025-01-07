class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> res;
        for(auto& w : words) {
            bool ok = false;
            for(auto& ww : words) {
                if(w == ww) continue;
                ok = ww.find(w) != string::npos;
                if(ok) break;
            }
            if(ok) res.push_back(w);
        }
        return res;
    }
};