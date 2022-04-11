class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        int dx[4]{0,1,0,-1}, dy[4]{-1,0,1,0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) continue;
                int cnt = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                grid[i][j] = 0;
                while(!q.empty()) {
                    auto p = q.front();
                    q.pop();
                    for(int k = 0; k < 4; k++) {
                        int nx = p.second + dx[k], ny = p.first + dy[k];
                        if(0 <= nx && nx < m && 0 <= ny && ny < n && grid[ny][nx]) {
                            cnt++;
                            grid[ny][nx] = 0;
                            q.push({ny, nx});
                        }
                    }
                }
                res = max(res, cnt);
            }
        }
        return res;
    }
};
