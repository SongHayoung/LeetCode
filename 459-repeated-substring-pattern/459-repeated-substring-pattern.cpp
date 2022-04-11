class Solution {
    vector<int> getPi(string s){
        vector<int> pi(s.length());
        for(int i = 1, j = 0; i < s.length(); i++) {
            while(j>0 and s[i] != s[j])
                j = pi[j-1];
            if(s[i] == s[j])
                pi[i] = ++j;
        }
        return pi;
    }
public:
    bool repeatedSubstringPattern(string s) {
        string m = (s + s).substr(1,s.length() * 2 - 2);
        vector<int> pi = getPi(s);
        for(int i = 0, j = 0; i < m.length(); i++) {
            while(j>0 and m[i] != s[j])
                j = pi[j-1];
            if(m[i] == s[j]) {
                if(++j == s.length()) return true;
            }
        }
        return false;
    }
};