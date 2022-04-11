class Solution {
    int checked[21][31];
    int helper(string& s, string& p, int sIndex, int pIndex) {
        if(sIndex == s.length() and pIndex == p.length()) return 1;
        if(sIndex > s.length() or pIndex > p.length()) return 0;
        if(checked[sIndex][pIndex] != -1) return checked[sIndex][pIndex];
        int& res = checked[sIndex][pIndex] = 0;
        
        if(pIndex + 1 < p.length() and p[pIndex + 1] == '*') {
            res = helper(s,p,sIndex,pIndex + 2);
            for(int i = sIndex; i < s.length() and res == 0 and (p[pIndex] == s[i] or p[pIndex] == '.'); i++) {
                res = helper(s,p,i + 1, pIndex + 2);
            }
        } else if(pIndex < p.length() and sIndex < s.length() and (p[pIndex] == '.' or s[sIndex] == p[pIndex])) {
             res = helper(s,p,sIndex + 1,pIndex + 1);
        }
        
        return res;
    }
public:
    bool isMatch(string s, string p) {
        memset(checked, -1, sizeof(checked));
        return helper(s,p,0,0) == 1;
    }
};