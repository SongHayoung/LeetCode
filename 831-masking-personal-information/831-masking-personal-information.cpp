class Solution {
    string email(string s) {
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            if(isalpha(s[i])) s[i] = tolower(s[i]);
        }
        auto pos = s.find('@');
        res = string(1,s[0]) + "*****" + s.substr(pos-1);
        return res;
    }
    string phone(string s) {
        int count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(isdigit(s[i])) count++;
        }
        string res = "";
        for(int i = s.length() - 1; i >= 0 and res.length() < 4; i--) {
            if(isdigit(s[i]))
               res.push_back(s[i]);
        }
        reverse(begin(res),end(res));
        if(count == 10) return "***-***-" + res;
        if(count == 11) return "+*-***-***-" + res;
        if(count == 12) return "+**-***-***-" + res;
        return "+***-***-***-" + res;
    }
public:
    string maskPII(string s) {
        return s.find('@') != string::npos ? email(s) : phone(s);
    }
};