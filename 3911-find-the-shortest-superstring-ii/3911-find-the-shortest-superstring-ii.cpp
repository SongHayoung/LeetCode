class Solution {
    vector<int> PI(string& p) {
        vector<int> pi(p.length());
        for(int i = 1, j = 0; i < p.length(); i++) {
            while(j and p[j] != p[i]) j = pi[j-1];
            if(p[j] == p[i]) pi[i] = ++j;
        }
        return pi;
    }
    int kmp(string& s, string& p) {
        auto pi = PI(p);
        int res = 0;
        for(int i = 0, j = 0; i < s.length(); i++) {
            while(j and s[i] != p[j]) j = pi[j-1];
            if(s[i] == p[j]) {
                ++j;
                if(j == p.length()) return -1;
            }
            if(i + 1 == s.length()) return j;
        }
        return 0;
    }
    string helper(string& A, string& B) {
        auto skip = kmp(A,B);
        if(skip == -1) return A;
        return A + B.substr(skip);
    }
public:
    string shortestSuperstring(string s1, string s2) {
        string res1 = helper(s1,s2), res2 = helper(s2,s1);
        return res1.length() > res2.length() ? res2 : res1;
    }
};