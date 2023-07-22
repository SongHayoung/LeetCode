class Solution {
    unordered_map<int, unordered_map<int, unordered_map<int, double>>> dp;
    double helper(int n, int k, int r, int c) {
        if(r < 0 or c < 0 or r >= n or c >= n) return 0;
        if(k == 0) return 1;
        if(dp.count(r) and dp[r].count(c) and dp[r][c].count(k)) return dp[r][c][k];
        dp[r][c][k] = (
            helper(n,k-1,r-1,c-2) + helper(n,k-1,r-2,c-1) +
            helper(n,k-1,r-2,c+1) + helper(n,k-1,r-1,c+2) +
            helper(n,k-1,r+1,c+2) + helper(n,k-1,r+2,c+1) +
            helper(n,k-1,r+2,c-1) + helper(n,k-1,r+1,c-2)
        ) / 8;
        return dp[r][c][k];
    }
public:
    double knightProbability(int n, int k, int row, int column) {
        return helper(n,k,row,column);
    }
};