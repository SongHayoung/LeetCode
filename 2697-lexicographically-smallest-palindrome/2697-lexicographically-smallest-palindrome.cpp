class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r) {
            if(s[l] != s[r]) {
                s[l] = s[r] = min(s[l], s[r]);
            }
            l += 1, r -= 1;
        }
        return s;
    }
};
