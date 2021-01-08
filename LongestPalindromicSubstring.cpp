class Solution {
public:
    string longestPalindrome(string s) {
        for(int i = 0; i < s.length(); i++) {
            for(int start = 0; start <= i; start++) {
                bool flag = true;
                for(int distance = 0; distance < (s.length() - i) / 2; distance++) {
                    if(s[start + distance] != s[s.length() - 1 - i + start - distance]) {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    return s.substr(start, s.length() - i);
            }
        }
        return "";
    }
};
