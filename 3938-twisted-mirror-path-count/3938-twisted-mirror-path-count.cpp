class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        long long mod = 1e9 + 7, n = grid.size(), m = grid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        vector<vector<vector<pair<int,int>>>> go(n, vector<vector<pair<int,int>>>(m, vector<pair<int,int>>(2)));
        for(int i = n - 1; i >= 0; i--) for(int j = m - 1; j >= 0; j--) {
            if(grid[i][j] == 0) go[i][j][0] = go[i][j][1] = {i,j};
            else {
                go[i][j][1] = j + 1 < m ? go[i][j+1][0] : pair<int,int>{i, j + 1};
                go[i][j][0] = i + 1 < n ? go[i+1][j][1] : pair<int,int>{i + 1, j};
            }
        }
        dp[0][0] = 1;
        int dy[2]{1,0},dx[2]{0,1};
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            for(int dir = 0; dir < 2; dir++) {
                int ni = i + dy[dir], nj = j + dx[dir];
                if(0 <= ni and ni < n and 0 <= nj and nj < m) {
                    auto [ny,nx] = go[ni][nj][!dir];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                        dp[ny][nx] = (dp[ny][nx] + dp[i][j]) % mod;
                    }
                }
            }
        }
        return dp[n-1][m-1];
    }
};