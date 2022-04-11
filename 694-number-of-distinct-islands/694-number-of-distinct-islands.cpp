class Solution {
    vector<pair<int,int>> bfs(vector<vector<int>>& grid, int y, int x) {
        int dy[4] = {-1,0,1,0};
        int dx[4] = {0,1,0,-1};
        int n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({y,x});
        vector<pair<int,int>> res{{y,x}};
        grid[y][x] = 0;
        
        while(!q.empty()) {
            auto [cy, cx] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = cy + dy[i], nx = cx + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and grid[ny][nx]) {
                    q.push({ny,nx});
                    grid[ny][nx] = 0;
                    res.push_back({ny,nx});
                }
            }
        }
        
        
        sort(res.begin(), res.end());
        
        return res;
    }
    pair<int,int> getDiff(pair<int, int>& p1, pair<int,int>& p2) {
        return {p1.first - p2.first, p1.second - p2.second};
    }
    bool verify(vector<vector<pair<int,int>>>& islands, vector<pair<int,int>>& target) {
        for(auto island : islands) {
            auto diff = getDiff(island[0], target[0]);
            bool eq = true;
            for(int i = 0; i < target.size() and eq; i++) {
                if(diff != getDiff(island[i], target[i]))
                    eq = false;
            }
            if(eq) return false;
        }
        return true;
    }
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int island = 0;
        unordered_map<int, vector<vector<pair<int,int>>>> mp;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j]) {
                    auto pos = bfs(grid,i,j);
                    if(verify(mp[pos.size()], pos)) {
                        mp[pos.size()].push_back(pos);
                        island++;
                    }
                }
        return island;
    }
};