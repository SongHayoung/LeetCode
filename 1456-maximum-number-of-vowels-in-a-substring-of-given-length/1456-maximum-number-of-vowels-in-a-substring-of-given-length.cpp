class Solution {
    bool isVowel(char ch) {
        return ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int res = 0, now = 0, n = s.length(), l = 0, r = 0;
        while(r < n) {
            if(isVowel(s[r++])) now++;
            if(r - l == k + 1 and isVowel(s[l++])) now--;
            res = max(res, now);
        }
        return res;
    }
};