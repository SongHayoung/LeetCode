class Solution {
    string substrZero(string &s) {
        int pos = 0;
        for(; pos < s.length(); pos++) {
            if(s[pos] != '0') break;
        }

        return pos == s.length() ? "0" : s.substr(pos);
    }
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> s;
        string str = "";
        bool flag = false;
        for(int i = 0; i < word.length(); i++) {
            if(flag && 'a' <= word[i] && word[i] <= 'z') {
                s.insert(substrZero(str));
                flag = false;
                str = "";
            } else if('0' <= word[i] && word[i] <= '9') {
                str += word[i];
                flag = true;
            }
        }
        if(flag)
            s.insert(substrZero(str));

        return s.size();
    }
};
