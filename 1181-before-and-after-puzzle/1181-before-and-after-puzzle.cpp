class Solution {
    pair<string, string> parse(string& s) {
        string f = "", l = "";
        for(int i = 0; i < s.length() and s[i] != ' '; i++) f.push_back(s[i]);
        for(int i = s.length() - 1; i >= 0 and s[i] != ' '; i--) l.push_back(s[i]);
        reverse(begin(l),end(l));
        return {f,l};
    }
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, vector<int>> first, last;
        for(int i = 0; i < phrases.size(); i++) {
            auto [f,l] = parse(phrases[i]);
            first[f].push_back(i);
            last[l].push_back(i);
        }
        unordered_set<string> us;
        
        for(auto [k, vec] : last) {
            for(auto& l : vec) {
                for(auto& f : first[k]) {
                    if(l == f) continue;
                    string now = phrases[l] + phrases[f].substr(k.length());
                    us.insert(now);
                }
            }
        }
        vector<string> res(begin(us),end(us));
        sort(begin(res),end(res));
        return res;
    }
};