class Solution {
    long long mod = 1e9 + 7;

    pair<long long, long long> fib(long long n) {
        if(n == 0) return {0, 1};

        auto [a, b] = fib(n / 2);

        long long c = a * ((2 * b % mod - a + mod) % mod) % mod;
        long long d = (a * a % mod + b * b % mod) % mod;

        if(n & 1) return {d, (c + d) % mod};
        return {c, d};
    }

public:
    int countGoodStrings(long long n) {
        return 2 * fib(n).first % mod;
    }
};