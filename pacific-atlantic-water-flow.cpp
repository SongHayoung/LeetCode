class Solution {
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {-1, 0, 1, 0};

    void bfs(vector<vector<int>> &m, vector<vector<bool>> &v, int &h, int &w, bool flag) {
        queue<pair<int, int>> q;
        if(flag) {
            for(int i = 0; i < w; i++) {
                v[0][i] = true;
                q.push({0, i});
            }
            for(int i = 0; i < h; i++) {
                v[i][0] = true;
                q.push({i, 0});
            }
        } else {
            for(int i = 0; i < w; i++) {
                v[h - 1][i] = true;
                q.push({h - 1, i});
            }
            for(int i = 0; i < h; i++) {
                v[i][w - 1] = true;
                q.push({i, w - 1});
            }
        }

        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int ny = p.first + dy[i];
                int nx = p.second + dx[i];
                if(0 <= nx && nx < w && 0 <= ny && ny < h && !v[ny][nx] && m[p.first][p.second] <= m[ny][nx]) {
                    q.push({ny, nx});
                    v[ny][nx] = true;
                }
            }
        }

        return;
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        if(matrix.empty() || matrix[0].empty()) return res;

        int h = matrix.size(), w = matrix[0].size();
        vector<vector<bool>> pacific(h, vector<bool>(w, false)), atlantic(h, vector<bool>(w, false));
        
        bfs(matrix, pacific, h, w, true);
        bfs(matrix, atlantic, h, w, false);

        for(int i = 0; i < h; i++)
            for(int j = 0; j < w; j++)
                if(pacific[i][j] && atlantic[i][j])
                    res.push_back(vector<int>{i, j});

        return res;
    }
};
