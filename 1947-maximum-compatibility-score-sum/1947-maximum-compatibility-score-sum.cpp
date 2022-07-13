class Solution {
    int dp[1<<8];
    int helper(vector<int>& A, vector<int>& B, int mask, int m, int p) {
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = 0;
        int n = A.size();
        for(int j = 0; j < n; j++) {
            if(mask & (1<<j)) continue;
            res = max(res, m - __builtin_popcount(A[p] ^ B[j]) + helper(A,B,mask | (1<<j),m,p+1));
        }
        return res;
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = students.size(), m = students[0].size();
        vector<int> A(n, 1<<10), B(n, 1<<10);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(students[i][j]) A[i] |= 1<<j;
                if(mentors[i][j]) B[i] |= 1<<j;
            }
        }
        memset(dp,-1,sizeof dp);
        dp[(1<<n) - 1] = 0;
        return helper(A,B,0,m,0);
    }
};