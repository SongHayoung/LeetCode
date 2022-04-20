class Solution {
public:
    bool isNumber(string s) {
        bool sign = s[0] == '+' or s[0] == '-', e = false, dot = false, digit = false;
        for(int i = sign; i < s.length(); i++) {
            if(s[i] == '+' or s[i] == '-') {
                if(sign) return false;
                if(!e and i != 0) return false;
                if(e and digit) return false;
                sign = true;
            } else if(isdigit(s[i])) {
                digit = true;
            } else if(s[i] == 'e' or s[i] == 'E') {
                if(!digit) return false;
                if(e) return false;
                sign = false;
                digit = false;
                e = true;
            } else if(s[i] == '.') {
                if(e) return false;
                if(dot) return false;
                dot = true;
            } else return false;
        }
        return digit;
    }
};