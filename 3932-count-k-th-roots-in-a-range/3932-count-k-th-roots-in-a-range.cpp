class Solution {
    long long helper(long long m, long long k, long long lim) {
        long long x = 1;
        for(int i = 0; i < k and x <= lim; i++) {
            x = x * m;
        }
        return x <= lim;
    }
    long long helper(long long n, long long k) {
        if(n <= 0) return 0;
        long long l = 1, r = n, res = 0;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(m,k,n);
            if(ok) {
                l = m + 1;
                res = m;
            } else r = m - 1;
        }

        return res;
    }
public:
    int countKthRoots(int l, int r, int k) {
        return helper(r,k) - helper(l-1,k) + !l;
    }
};
