class Solution {
public:
    int mySqrt(int x) {
        if(!x) return 0;
        long long l = 1, r = INT_MAX, res = 0;
        while(l <= r) {
            long long m = l + (r-l) / 2;
            if(m * m <= x) {
                res = max(res, m);
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};