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

Combination comb(101010);
class Solution {
    public:
    int minMaxSums(vector<int>& nums, int k) {
        vector<long long> cnt(nums.size() + 1, 0);
        

        for (int i = 2; i <= nums.size(); ++i) {
            for (int j = 1; j <= min(k - 2, i - 2); ++j) {
                cnt[i] = (cnt[i] + comb.nCr(i - 2, j)) % mod;
            }
        }

        vector<long long> prefix(cnt.size(), 0);
        for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] = (prefix[i - 1] + cnt[i]) % mod;
        }

        long long res = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); ++i) {
            long long now = (prefix[i + 1] + prefix[nums.size() - i] + 2) % mod;
            if (k >= 2) now = (now + nums.size() - 1) % mod;
            res = (res + now * nums[i] % mod) % mod;
        }

        return res;
    }
};