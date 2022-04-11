class Solution {
public:
    string removeKdigits(string s, int k) {
        if(s.length() == k) return "0";
        string res = "";
        for(int i = 0; i < s.length(); i++) {
            while(res.length() > 0 and k > 0 and res.back() > s[i]) {
                k--;
                res.pop_back();
            }
            res += s[i];
            if(res == "0") res.pop_back();
        }
        
        while(k and res.length()) {
            k--;
            res.pop_back();
        }
        
        return res.length() == 0 ? "0" : res;
    }
};