class Solution {
    int dy[4]{-1,0,1,0}, dx[4]{0,1,0,-1};
    bool dfs(vector<vector<char>>& board, int n, int m, int y, int x, string& word, int pos) {
        if(word[pos] != board[y][x]) return false;
        if(pos == word.length() - 1) return true;
        board[y][x] = '#';
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(0 <= ny and ny < n and 0 <= nx and nx < m) {
                if(dfs(board,n,m,ny,nx,word,pos+1)) return true;
            }
        }
        
        board[y][x] = word[pos];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(dfs(board,n,m,i,j,word,0)) return true;
        }
        return false;
    }
};