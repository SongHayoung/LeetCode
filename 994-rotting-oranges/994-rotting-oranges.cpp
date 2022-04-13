class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), rotten = 0, days = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) q.push({i,j});
                else if(grid[i][j] == 1) rotten++;
            }
        }
        
        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
        while(!q.empty() and rotten) {
            int sz = q.size();
            while(sz--) {
                auto [y, x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0<=nx and nx < m and 0 <= ny and ny < n and grid[ny][nx] == 1) {
                        grid[ny][nx] = 2;
                        rotten--;
                        q.push({ny,nx});
                    }
                }
            }
            days++;
        }
        return rotten ? -1 : days;
    }
};