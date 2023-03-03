class Solution {
    vector<int> getPi(string& s) {
        vector<int> pi(s.length());
        for(int i = 1, j = 0; i < s.length(); i++) {
            while(j > 0 and s[i] != s[j])
                j = pi[j-1];
            if(s[i] == s[j])
                pi[i] = ++j;
        }
        return pi;
    }
public:
    int strStr(string st, string ne) {
        if(ne.length() == 0) return 0;
        vector<int> pi = getPi(ne);
        for(int i = 0, j = 0; i < st.length(); i++) {
            while(j > 0 and st[i] != ne[j])
                j = pi[j-1];
            if(st[i] == ne[j])  {
                j++;
                if(j == ne.length())
                    return i - j + 1;
            }
        }
        
        return -1;
    }
};