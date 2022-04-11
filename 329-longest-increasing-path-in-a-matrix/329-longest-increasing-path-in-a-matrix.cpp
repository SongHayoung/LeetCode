class Solution {
    int n, m;
    vector<vector<int>> dp;
    int floodfill(int y, int x, vector<vector<int>>& matrix) {
            if(dp[y][x] != -1) return dp[y][x];
            dp[y][x] = 1;
            if(0 <= y + 1 and y + 1 < n and 0 <= x and x < m and matrix[y+1][x] > matrix[y][x]) {
                dp[y][x] = max(dp[y][x], 1 + floodfill(y+1,x,matrix));
            }
            if(0 <= y - 1 and y - 1 < n and 0 <= x and x < m and matrix[y-1][x] > matrix[y][x]) {
                dp[y][x] = max(dp[y][x], 1 + floodfill(y-1,x,matrix));
            }
            if(0 <= y and y < n and 0 <= x + 1 and x + 1 < m and matrix[y][x+1] > matrix[y][x]) {
                dp[y][x] = max(dp[y][x], 1 + floodfill(y,x+1,matrix));
            }
            if(0 <= y and y < n and 0 <= x - 1 and x - 1 < m and matrix[y][x-1] > matrix[y][x]) {
                dp[y][x] = max(dp[y][x], 1 + floodfill(y,x-1,matrix));
            }
            return dp[y][x];
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        dp = vector<vector<int>>(n, vector<int>(m,-1));
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res = max(res, floodfill(i,j,matrix));
            }
        }
        return res;
    }
};