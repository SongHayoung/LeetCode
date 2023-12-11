class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        long long mod = 1e9 + 7, cent = 1, r = 0, c = 0, o = 0;
        while(k--) {
            long long pcent = cent, pr = r, pc = c, po = o;
            cent = (pr * (m - 1) + pc * (n - 1)) % mod;
            r = (pr * (m - 2) + pcent + po * (n - 1)) % mod;
            c = (pc * (n - 2) + pcent + po * (m - 1)) % mod;
            o = (po * (m - 2) + po * (n - 2) + pc + pr) % mod;
        }
        if(source == dest) return cent;
        if(source[0] == dest[0]) return r;
        if(source[1] == dest[1]) return c;
        return o;
    }
};