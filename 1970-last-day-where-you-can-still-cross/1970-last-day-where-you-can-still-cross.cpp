class Solution {
    bool connected(vector<vector<bool>>& matrix, int n, int m) {
        queue<pair<int,int>> q;
        for(int i = 0; i < m; i++)
            if(!matrix[0][i]) {
                q.push({0,i});
                matrix[0][i] = true;
            }
        int dy[4] = {-1,0,1,0}, dx[4] = {0,1,0,-1};
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !matrix[ny][nx]) {
                    if(ny == n - 1) return true;
                    matrix[ny][nx] = true;
                    q.push({ny,nx});
                }
            }
        }
        
        return false;
    }
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int l = 0, r = cells.size() - 1;
        while(l <= r) {
            int m = (l + r) / 2;
            vector<vector<bool>> matrix(row, vector<bool>(col, false));
            for(int i = 0; i <= m; i++)
                matrix[cells[i][0] - 1][cells[i][1] - 1] = true;
            if(connected(matrix, row, col)) l = m + 1;
            else r = m - 1;
        }
        return l;
    }
};