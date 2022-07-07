class Solution {
public:
    int countSubstrings(string s, string t) {
        int n = s.length(), m = t.length(), res = 0;
        int ldp[101][101] = {}, rdp[101][101] = {};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i] == t[j])
                    ldp[i+1][j+1] = ldp[i][j] + 1;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                if(s[i] == t[j])
                    rdp[i][j] = rdp[i+1][j+1] + 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(s[i] != t[j])
                    res += (ldp[i][j] + 1) * (rdp[i+1][j+1] + 1);
            }
        }
        return res;
    }
};