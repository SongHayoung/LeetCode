class Solution {
public:
    bool hasSpecialSubstring(string s, int k) {
        int n = s.length();
        for(int i = 0; i <= n - k; i++) {
            bool ok = true;
            for(int j = i; j < i + k and ok; j++) {
                if(s[j] != s[i]) ok = false;
            }
            if(ok) {
                if(i and s[i] == s[i-1]) ok = false;
                if(i + k < n and s[i] == s[i+k]) ok = false;
            }
            if(ok) return ok;
        }
        return false;
    }
};