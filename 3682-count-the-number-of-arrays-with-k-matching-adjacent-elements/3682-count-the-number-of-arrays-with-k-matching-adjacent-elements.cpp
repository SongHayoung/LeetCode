#include <vector>

using namespace std;

struct Combination {
    vector<long long> fac, inv;
    long long n, MOD;

    long long modpow(long long n, long long x, long long MOD) {
        if (x < 0) {
            return modpow(modpow(n, -x, MOD), MOD - 2, MOD);
        }
        n %= MOD;
        long long res = 1;
        while (x) {
            if (x & 1) {
                res = res * n % MOD;
            }
            n = n * n % MOD;
            x >>= 1;
        }
        return res;
    }

    Combination(long long _n, long long MOD) : n(_n + 1), MOD(MOD) {
        fac = inv = vector<long long>(n, 1);
        for (long long i = 1; i < n; ++i) {
            fac[i] = fac[i - 1] * i % MOD;
        }
        inv[n - 1] = modpow(fac[n - 1], MOD - 2, MOD);
        for (long long i = n - 2; i >= 1; --i) {
            inv[i] = inv[i + 1] * (i + 1) % MOD;
        }
    }

    long long fact(long long n) { return fac[n]; }

    long long nCr(long long n, long long r) {
        if (n < r || n < 0 || r < 0) return 0;
        return fac[n] * inv[r] % MOD * inv[n - r] % MOD;
    }
};

long long modpow(long long n, long long x, long long MOD) {
    if (x < 0) {
        return modpow(modpow(n, -x, MOD), MOD - 2, MOD);
    }
    n %= MOD;
    long long res = 1;
    while (x) {
        if (x & 1) {
            res = res * n % MOD;
        }
        n = n * n % MOD;
        x >>= 1;
    }
    return res;
}

constexpr long long MOD = 1e9 + 7;
Combination comb(1e5, MOD);

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        if (m == 1) return k == n - 1;
        return m * modpow(m - 1, n - 1 - k, MOD) % MOD * comb.nCr(n - 1, n - 1 - k) % MOD;
    }
};