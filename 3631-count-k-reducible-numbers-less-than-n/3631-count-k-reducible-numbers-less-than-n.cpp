class Solution {
    long long mod = 1e9 + 7;
    long long binom[808][808];
    long long nCr(int n, int r) {
        if(n - r < r) return nCr(n, n-r);
        if(binom[n][r]) return binom[n][r];
        if(r == 0) return 1;
        return binom[n][r] = (nCr(n-1,r-1) + nCr(n-1,r)) % mod;
    }
    long long helper(string& s, int r, int pos, bool less) {
        if(r == 0) return pos != s.length() and count(begin(s) + pos, end(s), '1');
        if(s.length() - pos < r) return 0;
        if(!less) {
            if(s[pos] == '0') return helper(s,r,pos+1,false);
            return (helper(s,r,pos+1,true) + helper(s,r-1,pos+1,false)) % mod;
        }
        memset(binom[s.length() - pos], 0, sizeof binom[s.length() - pos]);
        return nCr(s.length() - pos, r);
    }
    bool isKReducible(int x, int k) {
        for(int i = 0; i < k; i++) {
            x = __builtin_popcount(x);
        }
        return x == 1;
    }
public:
    int countKReducibleNumbers(string& s, int k) {
        vector<int> kReducibles;
        for(int i = 1; i < s.length(); i++) {
            if(isKReducible(i,k - 1)) kReducibles.push_back(i);
        }
        long long res = 0;
        for(auto& r : kReducibles) {
            res = (res + helper(s,r,0,false)) % mod;
        }
        return res;
    }
};