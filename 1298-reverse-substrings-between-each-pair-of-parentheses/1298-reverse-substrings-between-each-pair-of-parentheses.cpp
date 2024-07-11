class Solution {
    string helper(string&s, int& p) {
        int n = s.length();
        string res = "";
        while(p < n and s[p] != ')') {
            if(s[p] == '(') {
                ++p;
                string rev = helper(s, p);
                reverse(begin(rev), end(rev));
                res += rev;
            } else {
                res.push_back(s[p++]);
            }
        }
        p++;
        return res;
    }
public:
    string reverseParentheses(string s) {
        int p = 0;
        return helper(s, p);
    }
};