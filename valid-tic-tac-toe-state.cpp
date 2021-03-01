class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int p1 = 0, p2 =0;
        int p1cnt = 0, p2cnt = 0;
        int dx[4] {1, 1, 0, 1}, dy[4] {0, 1, 1, -1};
        for(int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++) {
                switch (board[i][j]) {
                    case 'X': p1++; break;
                    case 'O': p2++; break;
                }
                if(board[i][j] == ' ') continue;
                for(int k = 0; k < 4; k++) {
                    for(int l = 0; l < 3; l++) {
                        int nx = j + l * dx[k], ny = i + l * dy[k];
                        if(0 > nx || nx > 2 || ny < 0 || ny > 2 || board[i][j] != board[ny][nx]) break;
                        if(l == 2){
                            switch (board[i][j]) {
                                case 'X': p1cnt++; break;
                                case 'O': p2cnt++; break;
                            }
                        }
                    }
                }
            }
        return !(p2 > p1 || p1 > p2 + 1) && ((p1cnt <= 2 && p2cnt == 0 && p1 > p2) || (p2cnt <= 2 && p1cnt == 0 && p1 == p2));
    }
};
