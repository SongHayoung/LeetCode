class Solution {
public:
    vector<vector<int>> minScore(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> r(n), c(m);
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> Q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                Q.push({grid[i][j], i,j});
            }
        }
        while(!Q.empty()) {
            auto [_, y,x] = Q.top(); Q.pop();
            int now = max(r[y], c[x]) + 1;
            r[y] = c[x] = grid[y][x] = now;
        }
        return grid;
    }
};