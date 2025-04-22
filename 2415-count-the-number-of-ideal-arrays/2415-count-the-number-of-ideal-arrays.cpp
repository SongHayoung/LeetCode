class Solution {
    long long fact[10101] = {}, inv[10101] = {};
    long long mod = 1e9 + 7;
    long long modpow(long long n, long long x) {
        if(!x) return 1;
        long long res = modpow(n,x>>1);
        res = (res * res) % mod;
        if(x & 1) res = (res * n) % mod;
        return res;
    }
    long long comb(long long x, long long y) {
        if(x < y) return 0;
        return fact[x] * inv[x-y] % mod * inv[y] % mod;
    }
    long long helper(vector<int>& A, int& n, int& ma) {
        long long gap = A.back();
        long long res = comb(n, A.size() - 1);
        for(long long i = gap * 2; i <= ma; i += gap) {
            A.push_back(i);
            res = (res + helper(A,n,ma)) % mod;
            A.pop_back();
        }
        return res;
    }
public:
    int idealArrays(int n, int ma) {
        fact[0] = inv[0] = 1;
        for(int i = 1; i <= n + 1; i++) {
            fact[i] = (fact[i-1] * i) % mod;
            inv[i] = modpow(fact[i], mod-2);
        }
        return helper(vector<int>() = {1}, n, ma);
    }
};