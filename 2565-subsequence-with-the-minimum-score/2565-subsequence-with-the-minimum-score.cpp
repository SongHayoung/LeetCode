class Solution {
public:
    int minimumScore(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> lmatch(m,INT_MAX), rmatch(m,INT_MAX);
        for(int i = 0, j = 0; i < n and j < m; i++) {
            if(s[i] == t[j]) {
                lmatch[j] = i;
                j += 1;
            }
        }
        int p = m - 1;
        while(p >= 0 and lmatch[p] == INT_MAX) p -= 1;
        int res = m - (p + 1);
        for(int i = n - 1, j = m - 1; i >= 0 and j >= 0; i--) {
            if(s[i] == t[j]) {
                rmatch[j] = i;
                p = min(p,j);
                while(p >= 0 and lmatch[p] >= rmatch[j]) p -= 1;
                if(p >= 0) {
                    res = min(res, (j-1) - (p + 1) + 1);
                }
                res = min(res, j);
                j -= 1;
            }
        }
        return max(0,res);
    }
};