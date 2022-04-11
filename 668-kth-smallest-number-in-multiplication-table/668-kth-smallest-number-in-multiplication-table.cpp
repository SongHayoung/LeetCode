class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 0, hi = m * n + 1;
        int res = INT_MAX;
        while(lo <= hi) {
            int mi = lo + (hi - lo) / 2;
            int count = getCount(mi, m, n);
            
            if(count >= k) res = min(res,mi);
            
            if(count < k) lo = mi + 1;
            else hi = mi - 1;
        }
        return res;
    }
    int getCount(int value, int m, int n) {
        int res = 0;
        for(int i = 1; i <= m; i++) {
            res += min(value / i, n);
        }
        return res;
    }
};