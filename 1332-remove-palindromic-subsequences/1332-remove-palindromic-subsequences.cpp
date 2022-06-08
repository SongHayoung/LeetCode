class Solution {
    int isPalindrome(string& s) {
        int start = 0, mid = s.length() / 2, end = s.length() - 1;
        for(; start <= mid; start++, end--)
            if(s[start] != s[end])
                return 2;
        return 1;    
    }
public:
    int removePalindromeSub(string s) {
        return s.length() == 0 ? 0 : isPalindrome(s);
    }
};