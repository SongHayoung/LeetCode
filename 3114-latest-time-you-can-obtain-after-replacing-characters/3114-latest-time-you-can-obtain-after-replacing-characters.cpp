class Solution {
    bool match(char a, char b, string& s) {
        if(s.length() == 1) s = "0" + s;
        if(a != '?' and s[0] != a) return false;
        if(b != '?' and s[1] != b) return false;
        return true;
    }
public:
    string findLatestTime(string s) {
        string t = "", m = "";
        for(int i = 0; i < 12; i++) {
            string now = to_string(i);
            if(match(s[0], s[1], now)) t = now;
        }
        for(int i = 0; i < 60; i++) {
            string now = to_string(i);
            if(match(s[3], s[4], now)) m = now;
        }
        return t + ":" + m;
    }
};