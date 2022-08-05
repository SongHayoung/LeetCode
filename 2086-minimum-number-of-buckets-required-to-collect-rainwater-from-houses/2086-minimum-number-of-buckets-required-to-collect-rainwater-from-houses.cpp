class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.length(), res = 0;
        if(n == 1) return s == "H" ? -1 : 0;
        if(s[0] == 'H' and s[1] == 'H') return -1;
        if(s[n-1] == 'H' and s[n-2] == 'H') return -1;
        for(int i = 1; i < n - 1; i++) {
            if(s[i] == 'H' and s[i-1] == 'H' and s[i + 1] == 'H') return -1;
        }
        for(int i = 1; i < n - 1; i++) {
            if(s[i] == '.' and s[i-1] == 'H' and s[i + 1] == 'H') {
                s[i] = 'B';
                s[i-1] = s[i+1] = 'X';
            }
        }
        for(int i = 0; i < n; i++) {
            if(s[i] != 'H') continue;
            if(i and s[i-1] == 'B') continue;
            if(i + 1 < n and s[i + 1] == 'B') continue;
            if(i and s[i-1] == '.') s[i-1] = 'B';
            else s[i+1] = 'B';
        }
        return count(begin(s), end(s), 'B');
    }
};