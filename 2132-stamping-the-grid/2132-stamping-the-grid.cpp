class Solution {
    vector<vector<int>> pre;
    int query(int y1, int x1, int y2, int x2) {
        if(y2 + 1 >= pre.size()) return 1;
        if(x2 + 1 >= pre[0].size()) return 1;
        return pre[y2+1][x2+1] - pre[y2+1][x1] - pre[y1][x2+1] + pre[y1][x1];
    }
    vector<vector<int>> masking(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        pre = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                pre[i+1][j+1] = grid[i][j] + pre[i+1][j] + pre[i][j+1] - pre[i][j];
            }
        }
        vector<vector<int>> mark(n, vector<int>(m));
        for(int i = 0; i < n - stampHeight + 1; i++) {
            for(int j = 0; j < m - stampWidth + 1; j++) {
                if(query(i,j,i+stampHeight-1,j+stampWidth-1) == 0) mark[i][j] = 1;
            }
        }
        vector<int> cnt(m);
        queue<pair<int, int>> q;
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            vector<int> pre(m+1);
            while(q.size() and q.front().first == i) {
                cnt[q.front().second]--;
                q.pop();
            }
            for(int j = 0; j < m; j++) {
                if(mark[i][j]) {
                    q.push({i+stampHeight, j});
                    cnt[j]++;
                }
                if(cnt[j]) {
                    pre[j] += cnt[j];
                    pre[j+stampWidth] -= cnt[j];
                }
            }
            for(int j = 0; j < m; j++) {
                if(j) pre[j] += pre[j-1];
                if(pre[j]) res[i][j] = 1;
                if(grid[i][j]) res[i][j] = 1;
            }
        }
        return res;
    }
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int n = grid.size(), m = grid[0].size();
        auto res1 = masking(grid,stampHeight,stampWidth);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(res1[i][j]) continue;
            return false;
        }
        return true;
    }
};