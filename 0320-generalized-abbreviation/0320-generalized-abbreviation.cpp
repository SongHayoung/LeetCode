class Solution {
    void helper(vector<string>& A, string& s, int p, string pre, bool digit, bool alpha) {
        if(p == s.length()) A.push_back(pre);
        else {
            if(alpha) {
                pre.push_back(s[p]);
                helper(A,s,p+1,pre,true,true);
                pre.pop_back();
            }
            if(digit) {
                for(int cnt = 1; p < s.length(); p++,cnt++) {
                    string nxt = pre + to_string(cnt);
                    helper(A,s,p+1,nxt,false,true);
                }
            }
        
        }
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        helper(res,word,0,"",true,true);
        return res;
    }
};