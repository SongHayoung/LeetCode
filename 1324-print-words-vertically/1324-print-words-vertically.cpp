class Solution {
    vector<string> parse(string s) {
        string token = "";
        vector<string> res;
        for(auto& ch : s) {
            if(ch == ' ') {
                res.push_back(token);
                token = "";
            } else token.push_back(ch);
        }
        res.push_back(token);
        return res;
    }
public:
    vector<string> printVertically(string s) {
        vector<string> vs = parse(s);
        int n = 1;
        for(auto& s : vs) n = max(n, (int)s.length());
        vector<string> res(n);
        for(int i = 0; i < vs.size(); i++) {
            for(int j = 0; j < vs[i].length(); j++) {
                while(res[j].length() < i) res[j].push_back(' ');
                res[j].push_back(vs[i][j]);
            }
        }
        
        return res;
    }
};