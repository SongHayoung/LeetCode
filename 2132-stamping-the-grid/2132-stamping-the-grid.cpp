class Solution {
    bool judge(vector<vector<int>>& grid) {
        int sum = 0;
        for(auto& r : grid)
            sum += accumulate(begin(r),end(r),0);
        return sum == grid.size() * grid[0].size();
    }
public:
    bool possibleToStamp(vector<vector<int>>& grid, int h, int w) {
        int n = grid.size(), m = grid[0].size();
        if(h > n or w > m) return judge(grid);
        vector<int> st(m, 0);
        vector<vector<bool>> mark(n, vector<bool>(m));
        for(int i = 0; i < h - 1; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) st[j] += 1;
                else st[j] = 0;
            }
        }
        for(int i = h - 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) st[j] += 1;
                else st[j] = 0;
            }
            queue<int> q;
            for(int j = 0; j < w - 1; j++) {
                if(st[j] < h) q.push(j);
            }
            for(int l = 0, r = w - 1; r < m; l++,r++) {
                while(!q.empty() and q.front() < l) q.pop();
                if(st[r] < h) q.push(r);
                if(q.empty()) mark[i-h+1][l] = true;
            }
        }
        
        vector<int> row(m + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mark[i][j]) {
                    row[j]++;
                    row[j + w]--;
                }
                if(i >= h and mark[i-h][j]) {
                    row[j]--;
                    row[j + w]++;
                }
            }
            int sum = 0;
            for(int j = 0; j < m; j++) {
                sum += row[j];
                if(!sum and !grid[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
};