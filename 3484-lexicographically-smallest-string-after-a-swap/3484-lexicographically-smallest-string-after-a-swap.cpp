class Solution {
    bool ok(char ch, char ch2) {
        if((ch ^ ch2) % 2 == 1) return false; 
        return ch > ch2;
    }
public:
    string getSmallestString(string s) {
        int n = s.length();
        for(int i = 1; i < n; i++) {
            if(ok(s[i-1], s[i])) {
                swap(s[i], s[i-1]);
                return s;
            }
        }
        return s;
    }
};
