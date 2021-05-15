class TicTacToe {
    vector<int> horizon;
    vector<int> vertical;
    int leftTop, rightTop, n;
    bool isHorizontalWin(int row, int player) {
        return horizon[row] == player * n;
    }
    bool isVerticalWin(int col, int player) {
        return vertical[col] == player * n;
    }
    bool isDiagonalWin(int row, int col, int player) {
        if(row == col && (row * 2 + 1) == n) return leftTopToRightDown(player) || rightTopToLeftDown(player);
        return row == col ? leftTopToRightDown(player) : row + col + 1 == n ? rightTopToLeftDown(player) : false;
    }
    bool leftTopToRightDown(int player) {
        return leftTop == player * n;
    }
    bool rightTopToLeftDown(int player) {
        return rightTop == player * n;
    }
    bool isWin(int row, int col, int player) {
        return isHorizontalWin(row, player) || isVerticalWin(col, player) || isDiagonalWin(row, col, player);
    }
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) : n(n), leftTop(0), rightTop(0) {
        horizon = vector<int>(n,0);
        vertical = vector<int>(n,0);
    }

    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        horizon[row] += player == 2 ? -1 : 1;
        vertical[col] += player == 2 ? -1 : 1;
        if(row == col) leftTop += player == 2 ? -1 : 1;
        if(row + col + 1 == n) rightTop += player == 2 ? -1 : 1;
        return isWin(row, col, player == 2 ? -1 : 1) ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */
