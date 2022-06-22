class Solution {
    bool check(vector<vector<char>>& G, int y, int x, int dy, int dx, char c) {
        int eq = 0, noteq = 0;
        while(0 <= y and y < 8 and 0 <= x and x < 8 and eq < 2) {
            if(G[y][x] == c) eq++;
            else if(G[y][x] == '.') return false;
            else noteq++;
            y += dy;
            x += dx;
        }
        
        return eq == 2 and noteq > 0;
    }
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {
        board[rMove][cMove] = color;
        if(check(board, rMove, cMove, -1, -1, color)) return true;
        if(check(board, rMove, cMove, -1, 0, color)) return true;
        if(check(board, rMove, cMove, -1, 1, color)) return true;
        if(check(board, rMove, cMove, 0, 1, color)) return true;
        if(check(board, rMove, cMove, 1, 1, color)) return true;
        if(check(board, rMove, cMove, 1, 0, color)) return true;
        if(check(board, rMove, cMove, 1, -1, color)) return true;
        if(check(board, rMove, cMove, 0, -1, color)) return true;
        return false;
    }
};