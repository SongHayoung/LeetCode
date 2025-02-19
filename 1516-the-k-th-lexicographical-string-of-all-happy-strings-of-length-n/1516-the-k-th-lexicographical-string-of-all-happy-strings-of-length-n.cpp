class Solution {
    bool helper(string& s, int n, int& k) {
        if(s.length() == n) {
            return --k == 0;
        } else {
            for(int i = 0; i < 3; i++) {
                if(s.empty() or s.back() != ('a' + i)) {
                    s.push_back('a' + i);
                    if(helper(s,n,k))
                        return true;
                    s.pop_back();
                }
            }
            return false;
        }
    }
public:
    string getHappyString(int n, int k) {
        string res = "";
        helper(res,n,k);
        return res;
    }
};