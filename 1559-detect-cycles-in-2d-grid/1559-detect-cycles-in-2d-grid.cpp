class Solution {
    int n,m;
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    vector<vector<bool>> vis;
    bool dfs(vector<vector<char>>& A, int y, int x, int py, int px) {
        if(vis[y][x]) {
            return true;
        }
        vis[y][x] = true;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx] == A[y][x]) {
                if(py == ny and px == nx) continue;
                if(dfs(A,ny,nx,y,x)) return true;
            }
        }
        return false;
    }
public:
    bool containsCycle(vector<vector<char>>& A) {
        n = A.size(), m = A[0].size();
        vis = vector<vector<bool>>(n, vector<bool>(m));
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(vis[i][j]) continue;
            if(dfs(A,i,j,-1,-1)) return true;
        }
        return false;
    }
};