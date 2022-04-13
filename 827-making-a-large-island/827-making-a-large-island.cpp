class Solution {
    int getArea(vector<vector<int>>& grid, int sy, int sx, int island) {
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0}, n = grid.size();
        queue<pair<int, int>> q;
        q.push({sy,sx});
        int counter = 1;
        grid[sy][sx] = island;
        
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < n and grid[ny][nx] == 1) {
                    counter++;
                    grid[ny][nx] = island;
                    q.push({ny,nx});
                }
            }
        }
        
        return counter;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        vector<int> area(2);
        int island = 2, n = grid.size(), res = 0;
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int count = getArea(grid,i,j,island);
                    area.push_back(count);
                    island++;
                    res = max(res, count);
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    int sumArea = 1; //self
                    unordered_set<int> counted;
                    for(int k = 0; k < 4; k++) {
                        int ny = i + dy[k], nx = j + dx[k];
                        if(0 <= ny and ny < n and 0 <= nx and nx < n and !counted.count(grid[ny][nx])) {
                            counted.insert(grid[ny][nx]);
                            sumArea += area[grid[ny][nx]];
                        }
                    }
                    res = max(res, sumArea);
                }
            }
        }
        
        return res;
    }
};