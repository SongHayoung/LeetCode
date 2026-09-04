class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        for(int i = 0, j = 0; i < s.length(); i++) {
            if(s[i] == y) swap(s[i], s[j++]);
        }
        return s;
    }
};