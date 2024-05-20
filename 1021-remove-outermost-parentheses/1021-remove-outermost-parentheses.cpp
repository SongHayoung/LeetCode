class Solution {
public:
    string removeOuterParentheses(string& s) {
        string res = "";
        int c = 0;
        for(auto& ch : s) {
            if(ch == '(') {
                if(++c != 1) res.push_back(ch);
            } else {
                if(--c != 0) res.push_back(ch);
            }
        }
        return res;
    }
};