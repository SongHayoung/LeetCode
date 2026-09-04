class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        priority_queue<array<int,3>> q;
        int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        vector<vector<int>> mat(n, vector<int>(m));
        for(auto& s : sources) {
            int r = s[0], c = s[1], col = s[2];
            mat[r][c] = col;
            q.push({col,r,c});
        }
        while(q.size()) {
            priority_queue<array<int,3>> qq;
            while(q.size()) {
                auto [val,y,x] = q.top(); q.pop();
                for(int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if(0 <= ny and ny < n and 0 <= nx and nx < m and !mat[ny][nx]) {
                        mat[ny][nx] = val;
                        qq.push({val,ny,nx});
                    }
                }
            }
            swap(q,qq);
        }
        return mat;
    }
};