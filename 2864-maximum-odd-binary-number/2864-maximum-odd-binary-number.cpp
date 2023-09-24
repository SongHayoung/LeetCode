
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        sort(rbegin(s), rend(s));
        for(int i = s.length() - 1; i >= 0; i--) {
            if(s[i] == '0') continue;
            s[i] = '0';
            s.back() = '1';
            break;
        }
        return s;
    }
};