class Solution {
    bool match(string& s, string& p) {
        for(int i = 0; i < p.length(); i++) {
            if(p[i] == 'I') {
                if(s[i] > s[i+1]) return false;
            }
            if(p[i] == 'D') {
                if(s[i] < s[i+1]) return false;
            }
        }
        return true;
    }
public:
    string smallestNumber(string pattern) {
        string perm = "123456789";
        string res = "9999999999";
        do {
            if(match(perm, pattern)) {
                res = min(res,perm.substr(0,pattern.length() + 1));
            }
        }while(next_permutation(begin(perm),end(perm)));
        return res;
    }
};