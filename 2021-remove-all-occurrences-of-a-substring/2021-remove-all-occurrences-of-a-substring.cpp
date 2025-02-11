class Solution {
    vector<int> getPi(string& s) {
        vector<int> pi(s.length(), 0);
        for(int i = 1, j = 0; i < s.length(); i++) {
            while(j>0 and s[i] != s[j]) {
                j = pi[j-1];
            }
            if(s[i] == s[j])
                pi[i] = ++j;
        }
        return pi;
    }
    string kmp(string& s, string &p) {
        vector<int> pi = getPi(p);
        vector<int> index;
        string res = "";
        for(int i = 0, j = 0; i < s.length(); i++) {
            res.push_back(s[i]);
            while(j and res.back() != p[j]) j = pi[j-1];
            if(res.back() == p[j]) {
                index.push_back(++j);
                if(j == p.length()) {
                    for(int j = 0; j < p.length(); j++) {
                        res.pop_back();
                        index.pop_back();
                    }
                    j = index.size() ? index.back() : 0;
                }
            } else index.push_back(j);

        }
        return res;
    }
public:
    string removeOccurrences(string s, string part) {
        return kmp(s,part);
    }
};