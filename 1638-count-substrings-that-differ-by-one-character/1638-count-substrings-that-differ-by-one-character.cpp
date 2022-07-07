class Solution {
    bool valid(string& s, int p1, string& t, int p2, int len) {
        int diff = 0;
        while(len-- and diff < 2) {
            if(s[p1++] != t[p2++]) diff++;
        }
        return diff == 1;
    }
public:
    int countSubstrings(string s, string t) {
        int n = s.length(), m = t.length(), res = 0;
        for(int len = 1; len <= min(n,m); len++) {
            for(int i = 0; i <= n - len; i++) {
                for(int j = 0; j <= m - len; j++) {
                    if(valid(s,i,t,j,len)) res += 1;
                }
            }
        }
        return res;
    }
};