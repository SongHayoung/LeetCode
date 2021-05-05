class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int n = b.size(), m = b[0].size();
        int dx[8]{0,1,1,1,0,-1,-1,-1}, dy[8]{-1,-1,0,1,1,1,0,-1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int neighbors = 0;
                for(int k = 0; k < 8; k++) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if(0 <= nx && nx < m && 0 <= ny && ny < n && (b[ny][nx] & 1))
                        neighbors++;
                }
                if(neighbors == 3 || (neighbors == 2 && b[i][j]))
                    b[i][j] |= 2;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                b[i][j] >>= 1;
        }
    }
};
