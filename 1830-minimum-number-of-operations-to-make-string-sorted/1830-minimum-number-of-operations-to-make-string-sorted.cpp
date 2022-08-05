class Solution {
    long long fac[3333], inv[3333], mod = 1e9 + 7;
    long long modpow(long long n, long long x) {
        if(x == 0) return 1;
        long long res = modpow(n, x>>1);
        res = (res * res) % mod;
        if(x & 1) res = (res * n) % mod;
        return res;
    }
public:
    int makeStringSorted(string s) {
        fac[0] = inv[0] = 1;
        for(int i = 1; i <= 3000; i++) {
            fac[i] = fac[i-1] * i % mod;
            inv[i] = modpow(fac[i], mod - 2);
        }
        long long freq[26] = {}, res = 0;
        for(int i = s.length() - 1; i >= 0; i--) {
            int p = s[i] - 'a';
            freq[p]++;
            long long ans = accumulate(begin(freq), begin(freq) + p, 0ll) * fac[s.length() - i - 1] % mod;
            for(auto& f : freq) ans = ans * inv[f] % mod;
            res = (res + ans) % mod;
        }
        return res;
    }
};