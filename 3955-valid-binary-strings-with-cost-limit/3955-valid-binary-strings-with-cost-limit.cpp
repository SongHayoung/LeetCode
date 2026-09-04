class Solution {
    void helper(int p, int n, int c, string& s, vector<string>& res) {
        if(p == n) res.push_back(s);
        else {
            s.push_back('0');
            helper(p+1,n,c,s,res);
            s.pop_back();
            if(s.size() == 0 or s.back() == '0' and c >= p) {
                s.push_back('1');
                helper(p+1,n,c-p,s,res);
                s.pop_back();
            }
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> res;
        string s = "";
        helper(0,n,k,s,res);
        return res;
    }
};
