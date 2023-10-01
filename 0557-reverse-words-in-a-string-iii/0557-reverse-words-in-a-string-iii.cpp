class Solution {
    void reverse(string& s, int l, int r) {
        while(l < r) {
            swap(s[l],s[r]);
            l++; r--;
        }
    }
public:
    string reverseWords(string s) {
        int l = s[0] == ' ' ? 1 : 0, r = s[0] == ' ' ? 1 : 0;
        while(l < s.length()) {
            while(r < s.length() and s[r] != ' ') r++;
            r--;
            reverse(s, l, r);
            l = r = r+=2;
        }
        return s;
    }
};