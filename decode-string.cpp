class Solution {
    string decode(string& s, int& pos) {
        stringstream ss;
        int repeat = 0;
        for(; pos < s.length(); pos++) {
            if('0' <= s[pos] && s[pos] <= '9') {
                repeat = repeat * 10 + (s[pos] & 0b1111);
            } else if(s[pos] == '[') {
                string str = decode(s, ++pos);
                while(repeat--) {ss << str;} repeat++;
            } else if(s[pos] == ']') {
                return ss.str();
            } else {
                ss << s[pos];
            }
        }
        return ss.str();
    }
public:
    string decodeString(string s) {
        int pos = 0;
        return decode(s, pos);
    }
};
