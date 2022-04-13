class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long l = 2, r = LONG_MAX, lcm = a * b /__gcd(a,b), mod = 1e9 + 7;
        while(l < r) {
            long m = l + (r - l) / 2;
            if((m / a + m / b - m / lcm) < n) l = m + 1;
            else r = m;
        }
        return l % mod;
    }
};