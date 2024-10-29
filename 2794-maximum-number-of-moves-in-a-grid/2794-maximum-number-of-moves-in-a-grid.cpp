class Solution {
    int helper(vector<vector<int>>& dp, vector<vector<int>>& A, int y, int x, int n, int m) {
        if(dp[y][x] != -1) return dp[y][x];
        int& res = dp[y][x] = 0;
        if(x + 1 < m) {
            if(y and A[y][x] < A[y-1][x+1]) res = max(res, helper(dp,A,y-1,x+1,n,m) + 1);
            if(A[y][x] < A[y][x+1]) res = max(res, helper(dp,A,y,x+1,n,m) + 1);
            if(y + 1 < n and A[y][x] < A[y+1][x+1]) res = max(res, helper(dp,A,y+1,x+1,n,m) + 1);
        }
        return res;
    }
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int res = 0;
        for(int i = 0; i < n; i++) {
                dp[i][0] = helper(dp,grid,i,0,n,m);
                res = max(res, dp[i][0]);
        }
        return res;
    }
};