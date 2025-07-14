class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto& ch : s) {
            if(isalpha(ch)) res.push_back(ch);
            else if(ch == '*') {
                if(res.size()) res.pop_back();
            } else if(ch == '#') res = res + res;
            else if(ch == '%') {
                reverse(begin(res), end(res));
            }
        }
        return res;
    }
};