class Solution {
public:
    string breakPalindrome(string s) {
        if(s.length() == 1) {
            return "";
        }
        bool skip = s.length() & 1;
        int mid = s.length() / 2;
        for(int i = 0; i < s.length(); i++) {
            if(skip and mid == i) continue;
            if(s[i] > 'a') {
                s[i] = 'a';
                return s;
            }
        }
        s.back() = 'b';
        return s;
    }
};