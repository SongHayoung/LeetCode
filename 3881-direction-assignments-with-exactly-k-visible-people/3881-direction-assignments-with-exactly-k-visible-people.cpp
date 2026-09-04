using ll = long long;
ll mod = 1e9 + 7;
typedef vector<ll> vll;
#define rep(i,m,n) for(ll i=m;i<n;i++)
#define rrep(i,m,n) for(ll i=n;i>=m;i--)
struct Combination {
    vll fac, inv;
    ll n, MOD;

    ll modpow(ll n, ll x, ll MOD = mod) { if(!x) return 1; ll res = modpow(n,x>>1,MOD); res = (res * res) % MOD; if(x&1) res = (res * n) % MOD; return res; }

    Combination(ll _n, ll MOD = mod): n(_n + 1), MOD(MOD) {
        inv = fac = vll(n,1);
        rep(i,1,n) fac[i] = fac[i-1] * i % MOD;
        inv[n - 1] = modpow(fac[n - 1], MOD - 2, MOD);
        rrep(i,1,n - 2) inv[i] = inv[i + 1] * (i + 1) % MOD;
    }

    ll fact(ll n) {return fac[n];}
    ll nCr(ll n, ll r) {
        if(n < r or n < 0 or r < 0) return 0;
        return fac[n] * inv[r] % MOD * inv[n-r] % MOD;
    }
};

Combination comb(1e5 + 1);
class Solution {
public:
    int countVisiblePeople(int n, int pos, int k) {
        ll res = 0;
        for(int left = 0; left <= min(k,pos); left++) {
            res = (res + comb.nCr(pos,left) * comb.nCr(n-pos-1, k - left)) % mod;
        }
        return res * 2 % mod;
    }
};