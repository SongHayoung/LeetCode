class Solution {
    long long mod = 1e9 + 7;
    vector<vector<long long>> dp;
    long long n, m;
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    long long dfs(int y, int x, vector<vector<int>>& g) {
        if(dp[y][x] != -1) return dp[y][x];
        long long& res = dp[y][x] = 1;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < m and g[y][x] < g[ny][nx]) {
                res = (res + dfs(ny,nx,g)) % mod;
            }
        }
        return res;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        long long res = 0;
        dp = vector<vector<long long>> (n, vector<long long>(m, -1));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                res = (res + dfs(i,j,grid)) % mod;
        return res;
    }
};