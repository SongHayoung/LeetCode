class Solution {
    long long dp[1<<14];
    bool bit(int x, int p) {
        return (x>>p) & 1;
    }
    long long helper(vector<int>& A, vector<int>& B, int mask, int pos) {
        int n = A.size();
        if(n == pos) return 0;
        if(dp[mask] != -1) return dp[mask];
        long long& res = dp[mask] = INT_MAX;
        for(int i = 0; i < B.size(); i++) {
            if(bit(mask,i)) continue;
            res = min(res, (A[pos] ^ B[i]) + helper(A,B,mask | (1ll<<i), pos + 1));
        }
        return res;
    }
public:
    int minimumXORSum(vector<int>& A, vector<int>& B) {
        memset(dp,-1,sizeof dp);
        return helper(A,B,0,0);
    }
};