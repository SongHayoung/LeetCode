class Solution {
    unordered_set<char> punch{'!','.',','};
    bool check(string& s) {
        if(s.length() == 0) return false;
        if(punch.count(s.back())) s.pop_back();
        for(int i = 0, fl = 0; i < s.length(); i++) {
            if(punch.count(s[i])) return false;
            if(isdigit(s[i])) return false;
            if(s[i] == '-') {
                if(i == 0 or i == s.length() - 1) return false;
                if(islower(s[i-1]) and islower(s[i+1])) {
                    if(++fl == 2) return false;
                } else return false;
            } else if(!islower(s[i])) return false;
        }
        return true;
    }
public:
    int countValidWords(string s) {
        s.push_back(' ');
        int res = 0;
        string now = "";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == ' ') {
                if(check(now)) res += 1;
                now = "";
            } else now.push_back(s[i]);
        }
        return res;
    }
};