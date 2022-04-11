class Solution {
    bool helper(string& s, bool rm, int l, int r) {
        if(l >= r) return true;
        if(s[l] == s[r]) return helper(s,rm,l+1,r-1);
        if(rm) return false;
        return helper(s,true,l+1,r) or helper(s,true,l,r-1);
    }
public:
    bool validPalindrome(string s) {
        return helper(s,false,0,s.length()-1);
    }
};