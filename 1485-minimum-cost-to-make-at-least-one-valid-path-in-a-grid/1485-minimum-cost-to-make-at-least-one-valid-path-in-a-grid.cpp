class Solution {
    vector<vector<int>> dp;
    int dx[5] = {0,1,-1,0,0}, dy[5] = {0,0,0,1,-1};
    int n, m;
    int solution(vector<vector<int>>& grid, int y, int x) {
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> q;
        q.push({0,y,x});
        while(!q.empty()) {
            auto [c, cy, cx] = q.top(); q.pop();
            if(cy == n-1 and cx == m-1) return c;
            for(int i = 1; i < 5; i++) {
                int ny = cy + dy[i], nx = cx + dx[i], nc = c + (i != grid[cy][cx]);
                if(0<=ny and ny < n and 0 <= nx and nx < m and dp[ny][nx] > nc) {
                    dp[ny][nx] = nc;
                    q.push({nc,ny,nx});
                }
            }
        }
        return -1;
    }
public:
    int minCost(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        dp = vector<vector<int>>(n, vector<int>(m, INT_MAX));
        return solution(grid,0,0);
    }
};