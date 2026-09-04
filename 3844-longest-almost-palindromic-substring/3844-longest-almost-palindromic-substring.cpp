
class Solution {
    int check1(string& s, int l, int r) {
        int n = s.length();
        while(0 <= l and r < n and s[l] == s[r]) {
            l--, r++;
        }
        if(l == -1 or r == n) {
            return min(n, r - l);
        }
        return max(check2(s,l,r+1), check2(s,l-1,r));
    }
    int check2(string& s, int l, int r) {
        int n = s.length();
        while(0 <= l and r < n and s[l] == s[r]) {
            l--,r++;
        }
        return r - l - 1;
    }
public:
    int almostPalindromic(string s) {
        int res = 0, n = s.length();
        if(n == 2) return 2;
        for(int i = 0; i < n; i++) {
            res = max(res, check1(s,i,i));
            if(i + 1 < n) {
                res = max(res, check1(s,i,i+1));
            }
            if(i + 2 < n ) {
                res = max(res, check2(s, i, i + 2));
            }
        }
        return res;
    }
};