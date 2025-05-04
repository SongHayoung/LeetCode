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

long long modpow(long long n, long long x, long long MOD = mod) {if(x<0){return modpow(modpow(n,-x,MOD),MOD-2,MOD);}n%=MOD;long long res=1;while(x){if(x&1){res=res*n%MOD;}n=n*n%MOD;x>>=1;}return res;}

long long dp[55][55][33][33];
Combination comb(55);
class Solution {
public:
    int magicalSum(int M, int K, vector<int>& A) {
        memset(dp,-1,sizeof dp);
        long long res = 0, n = A.size();
        for(int i = 0; i < n; i++) {
            for(int carry = 0; carry <= 50; carry++) {
                for(int used = 0; used < M; used++) {
                    for(int set = 0; set <= K; set++) {
                        for(int now = !used; now + used <= M; now++) {
                            long long val = dp[i][carry][used][set], cur = modpow(A[i], now) * comb.nCr(M - used,now) % mod;
                            if(val == -1) {
                                if(used == 0 and carry + set) continue;
                                if(used or carry or set) continue;
                            }
                            
                            val = used ? val * cur % mod : cur;

                            if(now + used == M) {
                                int bits = set + __builtin_popcountll(carry + now);
                                if(bits == K) res = (res + val) % mod;
                            } else if(i + 1 < A.size()) {
                                int nused = used + now;
                                int nset = set + (carry + now) % 2, bits = (carry + now) / 2;
                                if(nset <= K) {
                                    if(dp[i+1][bits][nused][nset] == -1) dp[i+1][bits][nused][nset] = 0;
                                    dp[i+1][bits][nused][nset] = (dp[i+1][bits][nused][nset] + val) % mod;
                                }
                            }
                        }
                    }
                }
            }
        }
        return res;
    }
};


