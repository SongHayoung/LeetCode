class Solution {
    const int MOD = 1e9 + 7;
    long fastPow(long n, long p) {
        long res = 1L;
        while(p) {
            if(p & 1)
                res = res * n % MOD;
            n = n * n % MOD;
            p>>=1;
        }
        return res;
    }
public:
    int maxNiceDivisors(int primeFactors) {
        if(primeFactors < 4)
            return primeFactors;
        int prefix = primeFactors % 3 == 0 ? 3 : primeFactors % 3 == 1 ? 4 : 6;
        return prefix * fastPow(3, primeFactors / 3 - 1) % MOD;
    }
};
