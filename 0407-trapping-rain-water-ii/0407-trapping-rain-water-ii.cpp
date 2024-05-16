class Solution {
    int mark[202][202];
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
public:
    int trapRainWater(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        memset(mark, 0, sizeof mark);
        priority_queue<array<int,3>,vector<array<int,3>>, greater<>> pq;
           for(int i = 0; i < n; i++) {
               pq.push({A[i][0],i,0});
               pq.push({A[i][m-1],i,m-1});
               mark[i][0] = mark[i][m-1] = 1;
            }
            for(int j = 1; j < m - 1; j++) {
                pq.push({A[0][j],0,j});
                pq.push({A[n-1][j],n-1,j});
                mark[0][j] = mark[n-1][j] = 1;
            }
        int res = 0;
        while(pq.size()) {
            auto [h,y,x] = pq.top(); pq.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !mark[ny][nx]) {
                    res += max(0, h - A[ny][nx]);
                    mark[ny][nx] = true;
                    pq.push({max(h,A[ny][nx]), ny,nx});
                }
            }
        }
        
        return res;
    }
};