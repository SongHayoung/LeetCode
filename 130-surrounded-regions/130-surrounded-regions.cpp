class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty())
            return;
        int h = board.size(), w = board[0].size();
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {-1, 0, 1, 0};
        vector<vector<bool>> isVisited(h, std::vector<bool>(w, false));
        queue<pair<int, int>> q;
        
        for(int i = 0; i < w; i++) {
            if(board[0][i] == 'O') {
                isVisited[0][i] = true;
                q.push({0,i});
            }
            if(board[h - 1][i] == 'O') {
                isVisited[h - 1][i] = true;
                q.push({h - 1, i});
            }
        }
        
        for(int i = 1; i < h; i++) {
            if(board[i][0] == 'O') {
                isVisited[i][0] = true;
                q.push({i, 0});
            }
            if(board[i][w - 1] == 'O') {
                isVisited[i][w - 1] = true;
                q.push({i, w - 1});
            }
        }
        
        while(!q.empty()) {
            auto p = q.front();
            q.pop();
            for(int i = 0; i < 4; i++) {
                int nx = p.second + dx[i];
                int ny = p.first + dy[i];
                if(0 <= nx && nx < w && 0 <= ny && ny < h && !isVisited[ny][nx] && board[ny][nx] == 'O') {
                    q.push({ny, nx});
                    isVisited[ny][nx] = true;
                }
            }
        }
        
        
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(!isVisited[i][j])
                    board[i][j] = 'X';
            }
        }

        return;
    }
};