
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
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();
        vector<int> ord(n);
        iota(begin(ord), end(ord),0);
        sort(begin(ord), end(ord), [&](int i, int j) {
            bool iAllOne = (nums0[i] == 0);
            bool jAllOne = (nums0[j] == 0);
            if (iAllOne != jAllOne) return iAllOne > jAllOne;
            if (iAllOne and jAllOne) return false;
            if(nums1[i] != nums1[j]) return nums1[i] > nums1[j];
            return nums0[i] < nums0[j];
        });
        long long res = 0, now = 1, inv = modpow(2,mod - 2, mod);
        for(int i = n - 1; i >= 0; i--) {
            int idx = ord[i];
            now = now * modpow(2, nums0[idx], mod) % mod;
            long long nxt = now * modpow(2, nums1[idx], mod) % mod;
            res = (res + nxt - 1 - (now  - 1) % mod + mod) % mod;
            now = nxt;
        }
        return res;
    }
};