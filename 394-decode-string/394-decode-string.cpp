class Solution {
    int parseInt(string& s, int& i) {
        int res = 0;
        while(i < s.length() and isdigit(s[i])) {
            res = res * 10 + s[i++] - '0';
        }
        return res;
    }
    string parse(string& s, int & i) {
        string res;
        int cnt = 1;
        while(i < s.length() and s[i] != ']') {
            if(s[i] == '[') {
                string parsed = parse(s,++i);
                while(cnt--) {
                    res += parsed;
                }
                cnt = 1;
            } else if(isdigit(s[i])) {
                cnt = parseInt(s,i);
            } else res += s[i++];
        }
        i++;
        return res;
    }
public:
    string decodeString(string s) {
        int i = 0;
        return parse(s,i);
    }
};