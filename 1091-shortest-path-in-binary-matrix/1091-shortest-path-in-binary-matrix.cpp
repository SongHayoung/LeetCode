class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[8]{-1,0,1,1,1,0,-1,-1}, dy[8]{-1,-1,-1,0,1,1,1,0}, n(grid.size());
        if(grid[n - 1][n - 1] || grid[0][0]) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;
        
        while(!q.empty() && !grid[n-1][n-1]) {
            auto p = q.front();
            q.pop();
            for(int i = 0; i < 8; i++) {
                int ny(p.first + dy[i]), nx(p.second + dx[i]);
                if(0 <= ny && ny < n && 0 <= nx && nx < n && !grid[ny][nx]) {
                    grid[ny][nx] = grid[p.first][p.second] + 1;
                    q.push({ny, nx});
                }
            }
        }
        
        return grid[n-1][n-1] ? grid[n-1][n-1] : -1;
    }
};