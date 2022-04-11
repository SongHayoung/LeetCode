class Solution {
    bool isNearShip(vector<vector<char>>& board, int y, int x) {
        if(y == -1 or y == board.size()) return false;
        if(x == -1 or x == board[y].size()) return false;
        return board[y][x] == 'X';
    }
    
    bool horizonShip(vector<vector<char>>& board, int y, int x) {
        return !isNearShip(board, y + 1, x) and !isNearShip(board, y - 1, x);
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        int res = 0;
        for(int i = 0; i < m; i++) { //check vertical
            for(int j = 0; j < n - 1; j++) {
                if(board[j][i] == '.') continue;
                if(board[j + 1][i] == '.') continue; //if no vertical, pass
                int nextJ = j + 2;
        
                while(nextJ < n and board[nextJ][i] == 'X') nextJ++;
                j = nextJ;
                res++;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == '.') continue;
                if(!horizonShip(board,i,j)) continue;
                int nextJ = j + 1;
                while(nextJ < m and board[i][nextJ] == 'X') nextJ++;
                j = nextJ;
                res++;
            }
        }
        
        return res;
    }
};