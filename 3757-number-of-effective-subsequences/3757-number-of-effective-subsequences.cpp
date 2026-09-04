class Solution {
    bool bit(int a, int i) {
        return ((a>>i)&1);
    }
public:
    int countEffective(vector<int>& nums) {
        long long mod = 1e9 + 7, n = nums.size(), res = 0, bi = 0;
        for (int x : nums) bi |= x;
        vector<int> bits;
        for (int b = 0; b < 31; ++b) if (bit(bi,b)) bits.push_back(b);
        int B = bits.size(), S = 1<<B;
        vector<int> cnt(S,0);
        for (int x : nums) {
            int m = 0;
            for (int i = 0; i < B; ++i) if (bit(x,bits[i])) m |= (1<<i);
            cnt[m]++;
        }
        vector<int> F = cnt;
        for(int i = 0; i < B; i++) for(int mask = 0; mask < S; mask++) {
            if (bit(mask, i)) F[mask] += F[mask ^ (1 << i)];
        }
        vector<long long> pow2(n+1,1);
        for (int i = 1; i <= n; ++i) pow2[i] = (pow2[i-1]*2)%mod;
        for (int T = 0; T < S; ++T) {
            int cT = F[(S-1) ^ T];
            long long ways = pow2[cT];
            if (__builtin_popcount(T) % 2 == 0) res = (res + ways) % mod;
            else res = (res - ways + mod) % mod;
        }
        return ((pow2.back() - res) % mod + mod) % mod;
    }
};
