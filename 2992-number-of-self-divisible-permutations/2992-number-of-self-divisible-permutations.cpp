int dp[1<<13];
class Solution {
    int helper(int mask, int pos, int n) {
        if(pos == n + 1) return mask == (1<<n) - 1;
        int& res = dp[mask];
        if(res != -1) return res;
        res = 0;
        for(int i = 1; i <= n; i++) {
            if((mask >> (i-1)) & 1) continue;
            if(__gcd(i,pos) != 1) continue;
            res += helper(mask | 1ll<<(i-1), pos + 1, n);
        }
        return res;
    }
public:
    int selfDivisiblePermutationCount(int n) {
        memset(dp,-1,sizeof dp);
        return helper(0,1,n);
    }
};