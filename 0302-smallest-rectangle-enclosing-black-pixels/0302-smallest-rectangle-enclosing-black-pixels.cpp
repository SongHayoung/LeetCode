class Solution {
public:
    int minArea(vector<vector<char>>& image, int y, int x) {
        int minRow = y, maxRow = y, minCol = x, maxCol = x;
        int n = image.size(), m = image[0].size();
        queue<pair<int, int>> q;
        q.push({y,x});
        image[y][x] = '0';
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        while(!q.empty()) {
            auto [cy, cx] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = cy + dy[i], nx = cx + dx[i];
                if(0 <= ny and ny < n and 0 <= nx and nx < m and image[ny][nx] == '1') {
                    image[ny][nx] = '0';
                    q.push({ny, nx});
                    minRow = min(minRow, ny);
                    minCol = min(minCol, nx);
                    maxRow = max(maxRow, ny);
                    maxCol = max(maxCol, nx);
                }
            }
        }
        
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
        
    }
};