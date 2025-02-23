class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.length() > 2) {
            string ss = "";
            for(int i = 0; i < s.length() - 1; i++) {
                int digit = (s[i] - '0' + s[i+1] - '0') % 10;
                ss.push_back(digit + '0');
            }
            swap(s,ss);
        }
        return s[0] == s[1];
    }
};