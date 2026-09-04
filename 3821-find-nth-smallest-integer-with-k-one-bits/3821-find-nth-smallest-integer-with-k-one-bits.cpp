long long ncr[66][66];
long long nCr(int n, int r) {
    if (r < 0 or r > n) return 0;
    if (r == 0 or r == n) return 1;
    if(ncr[n][r] != -1) return ncr[n][r];
    return ncr[n][r] = nCr(n-1,r-1) + nCr(n-1,r);
}

class Solution {
public:
    long long nthSmallest(long long n, int k) {
        memset(ncr,-1,sizeof ncr);
        long long res = 0;
        for(long long i = 50; k and i; i--) {
            long long cnt = nCr(i-1,k);
            if(n > cnt) {
                n -= cnt;
                k -= 1;
                res |= 1ll<<(i - 1);
            }
        }
        return res;
    }
};
