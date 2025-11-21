class Solution {
    bool walls[202][202];
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
public:
    int trapRainWater(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> q;
        memset(walls,0,sizeof walls);
        auto push = [&](int y, int x) {
            walls[y][x] = true;
            q.push({A[y][x],y,x});
        };
        for(int i = 0; i < n; i++) {
            push(i,0), push(i,m-1);
        }
        for(int j = 1; j < m - 1; j++) {
            push(0,j), push(n-1,j);
        }
        int res = 0;
        while(q.size()) {
            auto [_,y,x] = q.top(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = dy[i] + y, nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and !walls[ny][nx]) {
                    if(A[ny][nx] < A[y][x]) {
                        res += A[y][x] - A[ny][nx];
                        A[ny][nx] = A[y][x];
                    }
                    push(ny,nx);
                }
            }
        }
        return res;
    }
};