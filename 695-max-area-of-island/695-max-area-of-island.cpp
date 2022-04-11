class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, cur = 0, n = grid.size(), m = grid[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) continue;
                cur++;
                queue<pair<int, int>> q;
                q.push({i,j});
                grid[i][j] = 0;

                while(!q.empty()) {
                    auto [y, x] = q.front(); q.pop();
                    for(int k = 0; k < 4; k++) {
                        int ny = y + dy[k], nx = x + dx[k];
                        if(0<=ny and ny < n and 0 <= nx and nx < m and grid[ny][nx]) {
                            cur++;
                            grid[ny][nx] = 0;
                            q.push({ny,nx});
                        }
                    }
                }
                
                
                
                
                res = max(res, cur);
                cur = 0;
            }
        }
        
        return res;
    }
};