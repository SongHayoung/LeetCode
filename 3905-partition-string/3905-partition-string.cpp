class Solution {
public:
    vector<string> partitionString(string s) {
        string p = "";
        unordered_set<string> us;
        vector<string> res;
        auto push = [&](string& s) {
            if(us.count(s)) return;
            us.insert(s);
            res.push_back(s);
            s = "";
        };
        for(int i = 0; i < s.length(); i++) {
            p.push_back(s[i]);
            push(p);
        }
        return res;
    }
};