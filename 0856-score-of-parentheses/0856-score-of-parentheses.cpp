class Solution {
    int helper(string& s, int& p) {
        int res = 0;
        while(p < s.length()) {
            p++;
            if(s[p] == ')') res += 1;
            else {
                res += 2 * helper(s,p);
            }
            p++;
            if(p == s.length() or s[p] == ')') break;
        }
        
        return res;
    }
public:
    int scoreOfParentheses(string s) {
        int p = 0;
        return helper(s,p);
    }
};