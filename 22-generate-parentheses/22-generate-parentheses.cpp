class Solution {
    vector<string> res;
    void helper(string& s, int open, int close, int len, int st) {
        if(len == s.length()) res.push_back(s);
        else {
            if(open) {
                s.push_back('(');
                helper(s, open - 1, close, len, st + 1);
                s.pop_back();
            }
            if(close and st) {
                s.push_back(')');
                helper(s, open, close - 1, len, st - 1);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        helper(string() = "", n, n, 2 * n, 0);
        return res;
    }
};