class Solution {
public:
    int lengthOfLastWord(string s) {
        int r = s.length() - 1;
        while(r >= 0 and s[r] == ' ') r--;
        int l = r;
        while(l >= 0 and s[l] != ' ') l--;
        return r - l;
    }
};