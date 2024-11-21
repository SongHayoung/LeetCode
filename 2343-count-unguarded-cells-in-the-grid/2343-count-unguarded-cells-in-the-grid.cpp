class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& G, vector<vector<int>>& W) {
        vector<vector<int>> A(n,vector<int>(m));
        int res = n * m;
        for(auto& w : W) {
            res--;
            A[w[0]][w[1]] = 15;
        }
        for(auto& g : G) {
            res--;
            A[g[0]][g[1]] = 15;
        }
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        for(auto& g : G) {
            int y = g[0], x = g[1];
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i], mask = 1<<i;
                while(0 <= ny and ny < n and 0 <= nx and nx < m and (A[ny][nx] & mask) == 0) {
                    if(!A[ny][nx]) res--;
                    A[ny][nx] |= mask;
                    ny += dy[i], nx += dx[i];
                }
            }
        }
        return res;
    }
};