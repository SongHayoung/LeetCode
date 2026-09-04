
class Solution {
    long long mod = 1e9 + 7;
    long long inv = modpow(2, mod - 2, mod);
    long long modpow(long long n, long long x, long long mod) {
        if(x<0){
            return modpow(modpow(n,-x,mod),mod-2,mod);
        }
        n%=mod;
        long long res=1;
        while(x){if(x&1){res=res*n%mod;}n=n*n%mod;x>>=1;}return res;
    }
    array<long long, 3> calc(long long n, long long k, long long m) {
        if (n <= m) return {0,n,0};
        long long cnt = (n - m - 1) / k + 1;
        return {((cnt * n % mod - k * cnt % mod * (cnt - 1) % mod * inv % mod) + mod) % mod, n - k * cnt, cnt};
    }
    bool helper(vector<int>& A, vector<int>& D, int op, int m) {
        long long cnt = 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i] < m) continue;
            long long diff = A[i] - m;
            cnt += (diff / D[i]) + 1;
        }
        return cnt <= op;
    }
public:
    int maxTotalValue(vector<int>& value, vector<int>& decay, int op) {
        int l = 0, r = *max_element(begin(value), end(value)), pick = r;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(value,decay,op,m);
            if(ok) {
                pick = m;
                r = m - 1;
            } else l = m + 1;
        }
        priority_queue<pair<int,int>> q;
        long long res = 0;
        for(int i = 0; i < value.size(); i++) {
            auto [sum,val,opp] = calc(value[i], decay[i], pick);
            res = (res + sum) % mod;
            if(val > 0) q.push({val,decay[i]});
            op -= opp;
        }
        while(op-- and q.size()) {
            auto [val, dec] = q.top(); q.pop();
            res = (res + val) % mod;
            if(val - dec > 0) q.push({val - dec, dec});
        }
        return res;
    }
};