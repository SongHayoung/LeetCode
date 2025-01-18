long long mod = 1e9 + 7;
struct Combination {
    vector<long long> fac, inv;
    long long n, MOD;

    long long modpow(long long n, long long x, long long MOD = mod) { if(!x) return 1; long long res = modpow(n,x>>1,MOD); res = (res * res) % MOD; if(x&1) res = (res * n) % MOD; return res; }

    Combination(long long _n, long long MOD = mod): n(_n + 1), MOD(MOD) {
        inv = fac = vector<long long>(n,1);
        for(int i = 1; i < n; i++) fac[i] = fac[i-1] * i % MOD;
        inv[n - 1] = modpow(fac[n - 1], MOD - 2, MOD);
        for(int i = n - 2; i >= 1; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    long long fact(long long n) {return fac[n];}
    long long nCr(long long n, long long r) {
        if(n < r or n < 0 or r < 0) return 0;
        return fac[n] * inv[r] % MOD * inv[n-r] % MOD;
    }
};

Combination comb(202020);
class Solution {
public:
    int distanceSum(int n, int m, int k) {
        long long res = 0, sum = 0;
        for(long long i = 0; i < n; i++) for(long long j = 0; j < m; j++) {
            res = (res + sum) % mod;
            sum = (sum + (i + 1) * (j + 1) - i * (m - j - 1)) % mod;
        }
        return res * comb.nCr(n * m - 2, k - 2) % mod;
    }
};
