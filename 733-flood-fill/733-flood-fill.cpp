class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor) return image;
        queue<pair<int, int>> q;
        int targetColor = image[sr][sc], n = image.size(), m = image[0].size();
        int dx[4] = {0,1,0,-1}, dy[4] = {-1,0,1,0};
        q.push({sr,sc});
        image[sr][sc] = newColor;
        while(!q.empty()) {
            auto [y, x] = q.front(); q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i], nx = x + dx[i];
                if(0 <= nx and nx < m and 0 <= ny and ny < n and image[ny][nx] == targetColor) {
                    image[ny][nx] = newColor;
                    q.push({ny,nx});
                }
            }
        }
        return image;
    }
};