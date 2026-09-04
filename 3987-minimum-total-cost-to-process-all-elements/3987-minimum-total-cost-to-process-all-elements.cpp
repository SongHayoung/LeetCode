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
    long long minimumCost(vector<int>& nums, int k) {
        long long op = 0, inv = modpow(2, mod-2, mod), power = k;
        
        for(auto& n : nums) {
            if(n <= power) power -= n;
            else {
                n -= power;
                op += n / k;
                n %= k;
                power = 0;
                if(n) {
                    power = k - n;
                    op++;
                }
            }
            op %= mod;
        }
        return op * (op + 1) % mod * inv % mod;
    }
};
