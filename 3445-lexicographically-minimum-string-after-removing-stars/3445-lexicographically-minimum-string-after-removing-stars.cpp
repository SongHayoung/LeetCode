class Solution {
public:
    string clearStars(string s) {
        map<char,vector<int>> mp;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '*') {
                if(mp.size()) {
                    begin(mp)->second.pop_back();
                    if(begin(mp)->second.empty()) mp.erase(begin(mp));
                }
            } else mp[s[i]].push_back(i);
        }
        vector<pair<int,char>> S;
        for(auto& [ch, ord] : mp) {
            for(auto& p : ord) S.push_back({p,ch});
        }
        sort(begin(S), end(S));
        string res = "";
        for(auto& [_,ch] : S) res.push_back(ch);
        return res;
    }
};