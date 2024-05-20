class Solution {
public:
    string removeOuterParentheses(string s) {
        string res = "";
        for(int i = 0, c = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                if(++c != 1) res.push_back(s[i]);
            } else {
                if(--c != 0) res.push_back(s[i]);
            }
        }
        return res;
    }
};