class Solution {
    bool isDescendingOrder(string& s, int pos, unsigned long long prev) {
        if(pos == s.length()) return true;
        unsigned long long val = 0;
        for(int i = pos; i < s.length(); i++) {
            val = val * 10 + (s[i] & 0b1111);
            if(val > prev) return false;
            if(val + 1 == prev && isDescendingOrder(s, i + 1, val)) return true;
        }
        return false;
    }
public:
    bool splitString(string s) {
        unsigned long long val = 0;
        for(int i = 0; i < s.length() - 1; i++) {
            val = val * 10 + (s[i] & 0b1111);
            if(isDescendingOrder(s, i + 1, val)) return true;
        }
        return false;
    }
};
