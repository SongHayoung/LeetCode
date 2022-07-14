class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> res;

        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int sz = 1, sum = 0;
                res.push_back(grid[i][j]);
                bool brk = false;
                while(!brk) {
                    int y = i, x = j;
                    for(int k = 0; k < sz and !brk; k++) {
                        sum += grid[y][x];
                        y += 1, x -= 1;
                        if(y < 0 or y >= n or x < 0 or x >= m) brk = true;
                    }
                    
                    for(int k = 0; k < sz and !brk; k++) {
                        sum += grid[y][x];
                        y += 1, x += 1;
                        if(y < 0 or y >= n or x < 0 or x >= m) brk = true;
                    }
                    
                    for(int k = 0; k < sz and !brk; k++) {
                        sum += grid[y][x];
                        y -= 1, x += 1;
                        if(y < 0 or y >= n or x < 0 or x >= m) brk = true;
                    }
                    
                    for(int k = 0; k < sz and !brk; k++) {
                        sum += grid[y][x];
                        y -= 1, x -= 1;
                        if(y < 0 or y >= n or x < 0 or x >= m) brk = true;
                    }
                    if(!brk) {
                        res.push_back(sum);
                        sz++;
                        sum = 0;
                    }
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                res.push_back(grid[i][j]);
            }
        }
        
        sort(begin(res), end(res));
        res.erase(unique(begin(res), end(res)), end(res));
        reverse(begin(res),end(res));
        res.resize(3);
        while(res.back() == 0) res.pop_back();
        return res;
    }
};