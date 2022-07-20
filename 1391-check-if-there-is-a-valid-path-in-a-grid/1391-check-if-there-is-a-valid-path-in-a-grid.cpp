class Solution {
    bool validDir(int street, int dir) {
        if(street == 1) return dir == 1 or dir == 3;
        if(street == 2) return dir == 0 or dir == 2;
        if(street == 3) return dir == 2 or dir == 3;
        if(street == 4) return dir == 1 or dir == 2;
        if(street == 5) return dir == 0 or dir == 3;
        if(street == 6) return dir == 0 or dir == 1;
        return false;
    }
    bool connected(int street1, int dir, int street2) {
        if(dir == 1) return street2 == 1 or street2 == 3 or street2 == 5;
        if(dir == 3) return street2 == 1 or street2 == 4 or street2 == 6;
        if(dir == 0) return street2 == 2 or street2 == 3 or street2 == 4;
        if(dir == 2) return street2 == 2 or street2 == 5 or street2 == 6;
        return false;
    }
public:
    bool hasValidPath(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> vis(n,vector<int>(m));
        vis[0][0] = true;
        queue<pair<int, int>> q;
        q.push({0,0});
        int dy[4]={-1,0,1,0}, dx[4]={0,1,0,-1};
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int dir = 0; dir < 4; dir++) {
                if(!validDir(A[y][x], dir)) continue;
                int ny = y + dy[dir],  nx = x + dx[dir];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !vis[ny][nx] and connected(A[y][x], dir , A[ny][nx])) {
                    q.push({ny,nx});
                    vis[ny][nx] = true;
                }
            }
        }
        return vis[n-1][m-1];
    }
};