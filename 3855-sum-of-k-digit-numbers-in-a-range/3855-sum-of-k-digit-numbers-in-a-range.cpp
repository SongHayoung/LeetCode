class Solution {
    long long mod = 1e9 + 7;
    long long modpow(long long n, long long x, long long mod) {
        if(x<0){
            return modpow(modpow(n,-x,mod),mod-2,mod);
        }
        n%=mod;
        long long res=1;
        while(x){if(x&1){res=res*n%mod;}n=n*n%mod;x>>=1;}return res;
    }
public:
    int sumOfNumbers(int l, int r, int k) {
        long long po = modpow(r - l + 1, k - 1, mod);
        long long res = 0, sum = 0;
        for(int i = l; i <= r; i++) sum += i;
        long long base = po * sum % mod;
        long long p = (modpow(10, k, mod) - 1 + mod) % mod;
        long long q = modpow(9, mod - 2, mod);
        return base * p % mod * q % mod;
    }
};