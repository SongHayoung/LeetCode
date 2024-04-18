class Solution {
public:
    int islandPerimeter(vector<vector<int>>& A) {
        int res = 0, dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
        int n = A.size(), m = A[0].size();
        for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
            if(!A[y][x]) continue;
            res += 4;
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and A[ny][nx]) res--;
            }
        }
        return res;
    }
};