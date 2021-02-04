class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        if(s.length() != t.length())
            return false;
        unordered_map<int, int> m;
        for(int i = 0; i < s.length(); i++) {
            m[(t[i] - s[i] + 26) % 26]++;
        }
        
        for(int i = 1; i < 26; i++) {
            if(m[i] && (m[i] - 1)*26 + i > k)
                return false;
        }
        return true;
    }
};
