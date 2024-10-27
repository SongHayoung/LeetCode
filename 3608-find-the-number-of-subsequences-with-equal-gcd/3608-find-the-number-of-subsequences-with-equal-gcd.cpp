class Solution {
    long long mod = 1e9 + 7;
    long long dp[202][202][202];
    long long helper(vector<int>& A, int p, int f, int s) {
        if(p == A.size()) return f == s and f > 0 and s > 0;
        if(dp[p][f][s] != -1) return dp[p][f][s];
        return dp[p][f][s] = (helper(A,p+1,f,s) + helper(A,p+1,__gcd(f,A[p]),s) + helper(A,p+1,f,__gcd(s,A[p]))) % mod;
    }
public:
    int subsequencePairCount(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return helper(nums,0,0,0);
    }
};
