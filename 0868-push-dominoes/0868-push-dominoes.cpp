class Solution {
public:
    string pushDominoes(string s) {
        int n = s.length(), p = 0;
        while(p < n) {
            while(p < n and s[p] == '.') p++;
            if(p == n) break;
            if(s[p] == 'L') {
                int np = p + 1;
                p--;
                while(p >= 0 and s[p] == '.') {
                    s[p] = 'L';
                    p--;
                }
                p = np;
            } else {
                int nj = p + 1;
                while(nj < n and s[nj] == '.') nj++;
                if(nj == n or s[nj] == 'R') {
                    while(p < nj) s[p++] = 'R';
                } else {
                    int np = nj + 1;
                    p++,nj--;
                    while(p < nj) {
                        s[p] = 'R'; s[nj] = 'L';
                        p++,nj--;
                    }
                    p = np;
                }
            }
        }
        return s;
    }
};