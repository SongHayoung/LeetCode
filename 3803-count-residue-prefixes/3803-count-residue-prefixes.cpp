class Solution {
public:
    int residuePrefixes(string s) {
        int res = 0;
        unordered_set<char> us;
        for(int i = 0; i < s.length(); i++) {
            us.insert(s[i]);
            res += us.size() == ((i + 1) % 3);
        }
        return res;
    }
};