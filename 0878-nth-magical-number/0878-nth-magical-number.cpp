long long mod = 1e9 + 7;
class Solution {
    long long __lcm(long long a, long long b) {
        long long g = __gcd(a,b);
        return a / g * b;
    }
    long long helper(long long n, long long a, long long b, long long m) {
        long long cnt = m / a + m / b - m / __lcm(a,b);
        return cnt >= n;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        long long l = 1, r = LLONG_MAX, res = LLONG_MAX;
        while(l <= r) {
            long long m = l + (r - l) / 2;
            bool ok = helper(n,a,b,m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res % mod;
    }
};