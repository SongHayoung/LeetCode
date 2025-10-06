class Solution {
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& mark, vector<vector<int>>& matrix, int marker) {
        int n = matrix.size(), m = matrix[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        vector<vector<bool>> visit(n,vector<bool>(m,false));
        if(marker == 2) {
            for(int i = 0; i < n; i++) visit[i][m-1] = true;
            for(int i = 0; i < m; i++) visit[n-1][i] = true;
        } else {
            for(int i = 0; i < n; i++) visit[i][0] = true;
            for(int i = 0; i < m; i++) visit[0][i] = true;
        }
            
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and matrix[y][x] <= matrix[ny][nx] and !visit[ny][nx]) {
                    mark[ny][nx] += marker;
                    q.push({ny,nx});
                    visit[ny][nx] = true;
                }
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        if(n == 1 or m == 1) {
            vector<vector<int>> res;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++)
                    res.push_back({i,j});
            return res;
        }
        vector<vector<int>> mark(n, vector<int>(m, 0));
        queue<pair<int,int>> pq, aq;
        for(int i = 0; i < n; i++) {
            pq.push({i, 0});
            aq.push({i, m-1});
            mark[i][0] += 1;
            mark[i][m-1] += 2;
        }
        for(int i = 1; i < m - 1; i++) {
            pq.push({0, i});
            aq.push({n-1, i});
            
            mark[0][i] += 1;
            mark[n-1][i] += 2;
        }
        pq.push({0,m-1});
        aq.push({n-1,0});
        
        mark[0][m-1] += 1;
        mark[n-1][0] += 2;
        
        bfs(pq,mark,matrix,1);
        bfs(aq,mark,matrix,2);
        
        vector<vector<int>> res;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mark[i][j] == 3) res.push_back({i,j});
            }
        }
        return res;
    }
};