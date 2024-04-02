class Solution {
    bool flag(int mask, int x) {
        return mask & (1ll<<x);
    }
    void helper(int& res, int h, int n, int mask, int dmask, int admask) {
        if(h == n) res++;
        else {
            for(int i = 0; i < n; i++) {
                if(flag(mask, i) or flag(dmask, i) or flag(admask, i)) continue;
                int nmask = mask | 1ll<<i;
                int ndmask = dmask | 1ll<<i;
                int ndamask = admask | 1ll<<i;
                helper(res, h + 1, n, nmask, ndmask<<1, ndamask>>1);
            }
        }
    }
public:
    int totalNQueens(int n) {
        int res = 0;
        helper(res, 0, n, 0, 0, 0);
        return res;
    }
};