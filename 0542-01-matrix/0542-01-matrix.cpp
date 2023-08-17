class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        
        vector<vector<int>> res(n,vector<int>(m,0));
        vector<vector<bool>> visit(n, vector<bool>(m,false));
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++) { //init all zeros
            for(int j = 0; j < m; j++) {
                if(!mat[i][j]) {
                    q.push({i,j});
                    visit[i][j] = true;
                }
            }
        }
        
        int distance = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [y, x] = q.front(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and !visit[ny][nx]) {
                        q.push({ny,nx});
                        visit[ny][nx] = true;
                        if(mat[ny][nx]) res[ny][nx] = distance;
                    }
                }
            }
            distance++;
        }
        
        return res;
    }
};