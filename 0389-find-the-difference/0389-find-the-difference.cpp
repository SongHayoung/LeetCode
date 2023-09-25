class Solution {
public:
    char findTheDifference(string& s, string& t) {
        char c = 0;
        for(int i = 0; i < s.length(); i++) c ^= s[i] ^ t[i];
        return c ^ t[t.length() - 1];
    }
};