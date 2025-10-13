class Solution {
public:
    bool scoreBalance(string s) {
        int tot = 0, now = 0;
        for(int i = 0; i < s.length(); i++) tot += s[i] - 'a' + 1;
        for(int i = 0; i < s.length(); i++) {
            now += s[i] - 'a' + 1;
            if(now * 2 == tot) return true;
        }
        return false;
    }
};