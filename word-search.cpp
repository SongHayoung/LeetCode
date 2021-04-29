class Solution {
    int n, m, len;
    int dx[4] {0, 1, 0, -1};
    int dy[4] {-1, 0, 1, 0};
    bool v[6][6] = {false, };
    bool chk(int y, int x, vector<vector<char>>& board, string& word, int pos) {
        if(pos == len) return true;
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(0 <= nx && nx < m && 0 <= ny && ny < n && !v[ny][nx] && board[ny][nx] == word[pos]) {
                v[ny][nx] = true;
                if(chk(ny, nx, board, word, pos + 1)) return true;
                v[ny][nx] = false;
            }
        }
        return false;
        
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size(), m = board[0].size(), len = word.length();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                v[i][j] = true;
                if(board[i][j] == word[0] && chk(i, j, board, word, 1)) return true;
                v[i][j] = false;
            }
        }
        return false;
    }
};
