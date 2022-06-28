class Solution {
    bool equal(string& o, string& p) {
        int n = o.length();
        unordered_map<char, char> mp;
        unordered_set<char> us;
        for(int i = 0; i < n; i++) {
            if(mp.count(o[i])) {
                if(mp[o[i]] != p[i]) return false;
            } else {
                if(us.count(p[i])) return false;
                us.insert(p[i]);
                mp[o[i]]=p[i];
            }
        }
        return true;
    }
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> res;
        for(auto& w : words)
            if(equal(w,pattern))
                res.push_back(w);
        return res;
    }
};