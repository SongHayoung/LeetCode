class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j])
                    q.push({i,j});
        int dis = -1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [y, x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and !grid[ny][nx]) {
                        grid[ny][nx] = 1;
                        q.push({ny,nx});
                    }
                }
            }
            dis++;
        }
        
        return dis == 0 ? -1 : dis;
    }
};