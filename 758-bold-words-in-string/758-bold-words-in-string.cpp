class Solution {
    vector<int> bold;
    vector<int> PI(string& s) {
        int n = s.length();
        vector<int> pi(n);
        for(int i = 1, j = 0; i < n; i++) {
            while(j and s[i] != s[j]) j = pi[j-1];
            if(s[i] == s[j])
                pi[i] = ++j;
        }
        return pi;
    }
    void kmp(string s, string p) {
        vector<int> pi = PI(p);
        int n = s.length();
        for(int i = 0, j = 0; i < n; i++) {
            while(j and s[i] != p[j]) j = pi[j-1];
            if(s[i] == p[j]) {
                if(++j == p.length()) {
                    bold[i - j + 1] += 1;
                    bold[i + 1] -= 1;
                    j = pi.back();
                }
            }
        }
    }
public:
    string boldWords(vector<string>& words, string s) {
        bold = vector<int>(s.length() + 1);
        for(auto& w : words) kmp(s,w);
        string res = bold[0] ? "<b>" : "";
        
        for(int i = 0; i < s.length(); i++) {
            if(i and bold[i] and !bold[i-1]) res += "<b>";
            res.push_back(s[i]);
            bold[i+1] += bold[i];
            if(bold[i] and !bold[i+1]) res += "</b>";
        }
        
        return res;
    }
};