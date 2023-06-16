class Solution {
    int mod = 1e9 + 7;
    int dp[1010][1010];
    int comb(int n, int m) {
        if(n == 0 or m == 0) return 1;
        if(dp[n][m] != -1) return dp[n][m];
        return dp[n][m] = (comb(n-1,m) + comb(n,m-1)) % mod;
    }
    int helper(vector<int>& A) {
        if(A.size() <= 1) return 1;
        vector<int> lower, higher;
        copy_if(begin(A), end(A), back_inserter(lower), [&](int i) {return i < A.front();});
        copy_if(begin(A), end(A), back_inserter(higher), [&](int i) {return i > A.front();});
        return 1ll * helper(lower) * helper(higher) % mod * comb(lower.size(), higher.size()) % mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        memset(dp, -1, sizeof dp);
        return helper(nums) - 1;
    }
};