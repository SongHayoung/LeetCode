
class Solution {
    long long mod = 1e9 + 7;
    pair<long long, long long> query(long long n) {
        long long width = n % 10, d = n / 10;
        long long x = 0, y = 0;
        string s = to_string(d);
        for(int i = 0; i < width and i < s.length(); i++) {
            x = x * 10 + s[i] - '0';
        }
        
        for(int i = width; i < s.length(); i++) {
            y = y * 10 + s[i] - '0';
        }
        return {x,y % (mod - 1)};
    }
    long long modpow(long long n, long long x, long long mod) {
        if(x<0){
            return modpow(modpow(n,-x,mod),mod-2,mod);
        }
        n%=mod;
        long long res=1;
        while(x){if(x&1){res=res*n%mod;}n=n*n%mod;x>>=1;}return res;
    }
public:
    int sumDecoded(vector<long long>& nums) {
        long long res = 0;
        for(auto& n : nums) {
            auto [x,y] = query(n);
            res = (res + modpow(x,y,mod)) % mod;
        }
        return res;
    }
};
