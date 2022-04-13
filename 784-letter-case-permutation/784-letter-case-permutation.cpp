class Solution {
    vector<string> res;
    bool isLowerCase(char ch) {
        return 'a'<=ch and ch <= 'z';
    }
    void backTracking(string& s, int i) {
        if(i == s.length()) {
            res.push_back(s);
            return;
        } else {
            backTracking(s, i + 1);
            if(!isdigit(s[i])) {
                if(isLowerCase(s[i])) {
                    s[i] = s[i] - 32;
                    backTracking(s,i+1);
                    s[i] = s[i] + 32;
                } else {
                    s[i] = s[i] + 32;
                    backTracking(s,i+1);
                    s[i] = s[i] - 32;
                }
            }
        }
    }
public:
    vector<string> letterCasePermutation(string s) {
        int i = 0;
        backTracking(s,i);
        return res;
    }
};