class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int dx[4]{0,1,0,-1}, dy[4]{-1,0,1,0};
        int n = grid.size(), m = grid[0].size(), fresh = 0, day = 0;
        bool beRot = true;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                switch (grid[i][j]) {
                    case 1 : fresh++; break;
                    case 2 : q.push({i,j}); break;
                }
            }
        }
        
        if(!fresh) return 0;
        if(q.empty()) return -1;
        
        while (beRot) {
            beRot = false;
            day++;
            int sz = q.size();
            while(sz--) {
                auto p = q.front();
                q.pop();
                for(int i = 0; i < 4; i++) {
                    int nx = p.second + dx[i], ny = p.first + dy[i];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && grid[ny][nx] == 1) {
                        fresh--;
                        grid[ny][nx] = 2;
                        q.push({ny, nx});
                        beRot = true;
                    }
                }
            }
        }
        

        return fresh ? -1 : day - 1;
    }
};
