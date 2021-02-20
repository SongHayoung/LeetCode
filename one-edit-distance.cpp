class Solution {
private:
    bool isInsert(string &s, string &t) {
        bool ret = false;
        if(t.length() == 0)
            return true;
        for(int i = 0, j = 0; i < s.length() && j < t.length(); i++, j++) {
            if(s[i] == t[j])
                continue;
            if(ret)
                return false;
            ret = true;
            --j;
        }
        return true;
    }
    
    bool isReplace(string &s, string &t) {
        bool ret = false;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == t[i])
                continue;
            
            if(ret)
                return false;
            ret = true;
        }
        return ret;
    }
public:
    bool isOneEditDistance(string s, string t) {
        return s.length() == t.length() - 1 ? isInsert(t, s) : t.length() == s.length() - 1 ? isInsert(s, t) : t.length() == s.length() ? isReplace(s, t) : false;
    }
};
