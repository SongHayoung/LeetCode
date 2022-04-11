class Solution {
    vector<pair<int, int>> p;
    int getCost(int y, int x) {
        int res = 0;
        for(auto [y1, x1] : p) {
            res += abs(y1-y) + abs(x1-x);
        }
        return res;
    }
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) p.push_back({i,j});
            }
        }
        
        int res = getCost(0,0);
        int y = 0, x = 0, cost;
        while(true) {
            int nextY, nextX, nextCost = INT_MAX;
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= nx and nx < m and 0 <= ny and ny < n) {
                    int curCost = getCost(ny,nx);
                    if(curCost < nextCost) {
                        nextCost = curCost;
                        nextY = ny, nextX = nx;
                    }
                }
            }
            if(nextCost >= res) break;
            res = nextCost;
            y = nextY, x = nextX;
        }
        
        return res;
    }
};