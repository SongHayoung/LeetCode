class Solution {
public:
    bool makePalindrome(string s) {
        int i = 0, j = s.length() - 1, change = 0;
        while(i <= j) {
            if(s[i++] != s[j--]) change++;
        }
        return change <= 2;
    }
};