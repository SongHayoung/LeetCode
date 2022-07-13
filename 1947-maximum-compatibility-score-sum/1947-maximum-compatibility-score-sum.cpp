class Solution {
    int dp[1<<17];
    void toBit(int n) {
        while(n) {
            cout<<(n & 1);
            n>>=1;
        }cout<<endl;
    }
    int helper(vector<int>& A, vector<int>& B, int mask, int m) {
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = 0;
        int n = A.size();
        for(int i = 0; i < n; i++) {
            if(mask & (1<<i)) continue;
            for(int j = 0; j < n; j++) {
                if(mask & (1<<(j + 8))) continue;
                res = max(res, m - __builtin_popcount(A[i] ^ B[j]) + helper(A,B,mask | (1<<i) | (1<<(j+8)),m));
            }
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
        return helper(A,B,0,m);
    }
};