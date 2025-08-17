class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<long long>> cost(n, vector<long long>(m, INT_MAX));
        map<int,vector<pair<int,int>>> ord;
        cost[0][0] = 0;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) ord[-grid[i][j]].push_back({i,j});
        for(int _ = 0; _ <= k; _++) {
            for(int y = 0; y < n; y++) {
                for(int x = 0; x < m; x++) {
                    if(y + 1 < n) cost[y+1][x] = min(cost[y+1][x], cost[y][x] + grid[y+1][x]);
                    if(x + 1 < m) cost[y][x+1] = min(cost[y][x+1], cost[y][x] + grid[y][x+1]);
                }
            }

            if(_ == k) break;
            long long best = INT_MAX;
            for(auto& [_,o] : ord) {
                for(auto& [y,x] : o) best = min(best, cost[y][x]);
                for(auto& [y,x] : o) cost[y][x] = best;
            }
        }
        return cost[n-1][m-1];
    }
};