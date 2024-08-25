class Solution {
    long long modpow(long long n, long long x, long long mod) {
        if(x<0){return modpow(modpow(n,-x,mod),mod-2,mod);}n%=mod;long long res=1;while(x){if(x&1){res=res*n%mod;}n=n*n%mod;x>>=1;}return res;
    }
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if(multiplier == 1) return nums;
        long long mod = 1e9 + 7;
        multiset<pair<long long, long long>> ms;
        long long ma = 0;
        for(int i = 0; i < nums.size(); i++) {
            ma = max(ma, nums[i] * 1ll);
            ms.insert({nums[i], i});
        }
        while(begin(ms)->first < ma and k) {
            auto [val, pos] = *begin(ms);
            ms.erase(begin(ms));
            ms.insert({val * multiplier, pos});
            k--;
        }
        long long x = k / nums.size();
        k %= nums.size();
        vector<long long> tmp(nums.size());
        while(ms.size()) {
            auto [val, pos] = *begin(ms);
            ms.erase(begin(ms));
            tmp[pos] = val % mod;
            if(k) {
                --k;
                tmp[pos] = tmp[pos] % mod * multiplier % mod;
            }
        }
        long long mul = modpow(multiplier,x,mod);
        vector<int> res;
        for(auto& x : tmp) {
            res.push_back(x % mod * mul % mod);
        }
        return res;
    }
};