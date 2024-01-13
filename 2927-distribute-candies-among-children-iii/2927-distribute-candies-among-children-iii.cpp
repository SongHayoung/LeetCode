class Solution {
public:
    long long distributeCandies(int n, int limit) {
        if(limit * 3 < n) return 0;
        long long res = 0, hold = min(limit, n);
        for(long long i = max(0, n - 2 * limit); i <= hold; i++) {
            long long x = n - i;
            if(x <= limit) {
                long long rem = hold - i + 1;
                res += rem * (2 * x - rem + 1) / 2 + rem;
                break;
            }
            else {
                long long l = i, r = min(n - limit - 1ll, hold), cnt = r - l + 1;
                res += 2 * limit * cnt + cnt;
                res -= cnt * (n - l + n - r) / 2;


                i = n - limit - 1;
            }
        }
        return res;
    }
};