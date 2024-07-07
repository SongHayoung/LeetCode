class Solution {
    void helper(vector<string>& res, string& s, int n) {
        if(s.length() == n) {
            res.push_back(s);
        } else {
            s.push_back('1');
            helper(res,s,n);
            s.pop_back();
            if(s.back() == '1') {
                s.push_back('0');
                helper(res,s,n);
                s.pop_back();
            }
        }
    }
public:
    vector<string> validStrings(int n) {
        if(n == 1) return {"0","1"};
        vector<string> res;
        string s0 = "0", s1 = "1";
        helper(res,s0,n);
        helper(res,s1,n);
        return res;
    }
};