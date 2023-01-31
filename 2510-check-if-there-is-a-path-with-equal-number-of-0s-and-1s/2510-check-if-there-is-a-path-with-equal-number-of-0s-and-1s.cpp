class Solution {
public:
    bool isThereAPath(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<bitset<222>>> dp(n, vector<bitset<222>>(m));
        dp[0][0][111] = 1;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(i) dp[i][j] |= dp[i-1][j];
                if(j) dp[i][j] |= dp[i][j-1];
                if(A[i][j]) dp[i][j]<<=1;
                else dp[i][j] >>=1;
            }
        }
        return dp[n-1][m-1][111];
    }
};