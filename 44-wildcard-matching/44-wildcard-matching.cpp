class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.length() == 0) return s.length() == 0;
        int n = 1;
        for(int i = 1; i < p.length(); i++) {
            if(p[i] == '*' and p[n-1] == '*') continue;
            p[n++] = p[i];
        }
        bool memo[2001][2001]{false};
        
        memo[0][0] = true;
        memo[0][1] = p[0] == '*';
        
        for(int i = 1; i <= s.length(); i++) {
            bool eq = false;
            for(int j = 1; j <= n; j++) {
                if(p[j - 1] == '?' or s[i - 1] == p[j - 1]) memo[i][j] = memo[i-1][j-1];
                else if(p[j - 1] == '*') memo[i][j] = memo[i-1][j] | memo[i][j-1];
                eq |= memo[i][j];
            }
            if(!eq) return false;
        }
        
        return memo[s.length()][n];
    }
};