class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        reverse(begin(s), end(s));
        while(s.size() and s.back() == ')') s.pop_back();
        reverse(begin(s), end(s));
        unordered_map<int,unordered_set<string>> mp;
        mp[0] = {""};
        for(auto& ch : s) {
            unordered_map<int,unordered_set<string>> mpp;
            auto push = [&](int c, string& s) {
                if(mpp[c].size() == 0) {
                    mpp[c] = {s};
                } else {
                    int len = (*begin(mpp[c])).length();
                    if(len == s.length()) {
                        mpp[c].insert(s);
                    } else if(len < s.length()) {
                        mpp[c] = {s};
                    }
                }
            };
            for(auto& [cnt, groups] : mp) {
                for(auto& g : groups) {
                    string gg = g;
                    push(cnt, gg);
                    int ncnt = cnt + (ch == '(' ? 1 : ch == ')' ? -1 : 0);
                    if(ncnt >= 0) {
                        gg.push_back(ch);
                        push(ncnt,gg);
                    }
                }
            }
            swap(mp,mpp);
        }
        vector<string> res;
        for(auto& ans : mp[0]) res.push_back(ans);
        return res;
    }
};