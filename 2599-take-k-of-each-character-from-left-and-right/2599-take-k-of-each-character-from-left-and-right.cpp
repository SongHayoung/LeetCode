class Solution {
public:
    int takeCharacters(string s, int k) {
        if(k == 0) return 0;
        int res = INT_MAX;
        int a = 0, b = 0, c = 0, p = 0;
        while(p < s.length()) {
            if(s[p] == 'a') a += 1;
            if(s[p] == 'b') b += 1;
            if(s[p] == 'c') c += 1;
            if(a >= k and b >= k and c >= k) break;
            p += 1;
        }
        if(a < k or b < k or c < k) return -1;
        res = min(res, p + 1);
        int r = s.length() - 1;
        while(p >= 0) {
            if(s[p] == 'a') a -= 1;
            if(s[p] == 'b') b -= 1;
            if(s[p] == 'c') c -= 1;
            while(a < k or b < k or c < k) {
                if(s[r] == 'a') a += 1;
                if(s[r] == 'b') b += 1;
                if(s[r] == 'c') c += 1;
                r -= 1;
            }
            if(a >= k and b >= k and c >= k) {
                res = min(res,p + (int)s.length() - r - 1);
            }
            p -= 1;
        }
        return res;
    }
};