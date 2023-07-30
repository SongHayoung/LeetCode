class Solution {
public:
    int countLetters(string s) {
        int res = 0;
        for(int l = 0, r = 0; r < s.length(); l = r) {
            while(r < s.length() and s[l] == s[r]) r += 1;
            res += (r - l) * (r - l + 1) / 2;
        }
        return res;
    }
};