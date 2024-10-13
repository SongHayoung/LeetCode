class Solution {
    long long mod = 1e9 + 7;
    long long modpow(long long n, long long x) {
        long long res = 1;
        while(x) {
            if(x & 1) res = res * n % mod;
            n = n * n % mod;
            x>>=1;
        }
        return res;
    }
public:
    int numberOfWays(int n, int x, int y) {
        vector<long long> fac(x+1,1), ifac(x+1,1);
        for(int i = 2; i < fac.size(); i++) fac[i] = fac[i-1] * i % mod;
        ifac[x] = modpow(fac[x], mod - 2);
        for(int i = ifac.size() - 2; i >= 1; i--) ifac[i] = ifac[i+1] * (i + 1) % mod;

        auto nCr = [&](int n, int r) {
            return fac[n] * ifac[r] % mod * ifac[n-r] % mod;
        };
        long long res = 0;
        vector<long long> dp(min(x,n) + 1);
        for(int i = 1; i <= min(x,n); i++) {
            dp[i] = modpow(i,n);
            for(int j = 1; j < i; j++) {
                dp[i] = (dp[i] - nCr(i,j) * dp[j] % mod + mod) % mod;
            }
            res = (res + dp[i] * nCr(x,i) % mod * modpow(y,i) % mod) % mod;
        }
        return res;
    }
};