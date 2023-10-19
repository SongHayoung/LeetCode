class Solution {
    string helper(string s) {
        string S = "";
        for(auto ch : s) {
            if(ch == '#') {
                if(S.length() > 0)
                    S.pop_back();
            } else S.push_back(ch);
        }
        return S;
    }
public:
    bool backspaceCompare(string s, string t) {        
        return helper(s) == helper(t);
    }
};