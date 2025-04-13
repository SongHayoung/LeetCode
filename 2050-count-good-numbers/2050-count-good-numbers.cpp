class Solution {
    const int mod = 1e9 + 7; 
    long modPow(int n, long long x){
        if (!x) return 1;
        long p = modPow(n, x>>1);
        return ((p * p) % mod) * (x & 1 ? n : 1) % mod;
    }
public:
    int countGoodNumbers(long long n) {
        return modPow(20, n>>1) * (n & 1 ? 5 : 1) % mod;
    }
};