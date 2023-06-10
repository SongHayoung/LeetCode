class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int res = 0, l = 0, r = 0, n = s.length(), now = 0;
        while(r < n) {
            while(r < n and now <= 1) {
                if(now <= 1) res = max(res, r - l + 1);
                if(r + 1 < n and s[r] == s[r+1]) now += 1;
                r += 1;
            }
            if(now <= 1) res = max(res, r - l);
            while(r < n and now > 1) {
                if(l + 1 < n and s[l] == s[l+1]) now -= 1;
                l += 1;
            }
        }
        return res;
    }
};
