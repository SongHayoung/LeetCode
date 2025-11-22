
class Solution {
    using i128 = __int128_t;
    i128 F(long long n) {
        i128 res = 0;
        for (int k = 0; k < 61; k++) {
            long long blk = 1LL << (k + 1);
            long long full = n / blk;
            long long rem  = n % blk;

            long long zeros = full * (1LL << k) + min(rem, (1LL << k));
            i128 z2 = (i128)zeros * zeros;
            i128 n2 = (i128)n * n;

            res += (n2 - z2) * (1LL << k);
        }
        return res;
    }

    i128 fn(long long n) {
        if (n <= 1) return 0;
        return (i128)n * (n - 1) / 2 * F(n);
    }
public:
    int maxSizedArray(long long s) {
        long l = 1, r = 2, res = 1;
        while(fn(r) <= s) r<<=1;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = (fn(m)) <= s;
            if(ok) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
};