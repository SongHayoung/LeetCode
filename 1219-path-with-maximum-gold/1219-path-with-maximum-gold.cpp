class Solution {
    int n,m;
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    void dfs(vector<vector<int>>& A, int y, int x, int& res, int now) {
        res = max(res, now + A[y][x]);
        if(!A[y][x]) return;
        now += A[y][x];
        int k = A[y][x];
        A[y][x] = 0;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx]) {
                dfs(A,ny,nx,res,now);
            }
        }
        A[y][x] = k;
    }
public:
    int getMaximumGold(vector<vector<int>>& A) {
        n = A.size(), m = A[0].size();
        int res = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(A,i,j,res,0);
            }
        }
        return res;
    }
};