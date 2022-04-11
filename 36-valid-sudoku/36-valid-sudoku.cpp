class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] {false, }, cols[9][9] {false, }, cells[9][9] {false, };

        for(int row = 0; row < 9; row++) {
            for(int col = 0; col < 9; col++) {
                if(board[row][col] == '.') continue;
                if(rows[row][(board[row][col] & 0b1111) - 1] ||
                 cols[col][(board[row][col] & 0b1111) - 1] ||
                        cells[row / 3 * 3 + col / 3][(board[row][col] & 0b1111) - 1] ) return false;
                rows[row][(board[row][col] & 0b1111) - 1] = cols[col][(board[row][col] & 0b1111) - 1] = cells[row / 3 * 3 + col / 3][(board[row][col] & 0b1111) - 1] = true;
            }
        }
        return true;
    }
};
