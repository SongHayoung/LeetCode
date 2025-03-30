class Solution {
    bool ok(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r) {
            if(s[l] != s[r]) return false;
            l++,r--;
        }
        return true;
    }
public:
    int longestPalindrome(string s, string t) {
        int res = 0, n = s.length(), m = t.length();
        for(int a = 0; a < n; a++) for(int b = a; b <= n; b++) {
            for(int c = 0; c < m; c++) for(int d = c; d <= m; d++) {
                if(ok(s.substr(a, b - a) + t.substr(c, d - c))) res = max(res, d - c + b - a);
            }
        }
        return res;
    }
};
