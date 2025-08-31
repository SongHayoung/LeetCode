class Solution {
    unordered_set<char> row[9], col[9], sq[9];
    bool checkRow(int y, int x, char target) {
        return !row[y].count(target);
    }
    bool checkCol(int y, int x, char target) {
        return !col[x].count(target);
    }
    bool checkSquare(int y, int x, char target) {
        return !sq[y/3*3+x/3].count(target);
    }
    bool check(int y, int x, char target) {
        return checkRow(y,x,target) and checkCol(y,x,target) and checkSquare(y,x,target);
    }
    void add(int y, int x, char target) {
        row[y].insert(target);
        col[x].insert(target);
        sq[y/3*3+x/3].insert(target);
    }
    void erase(int y, int x, char target) {
        row[y].erase(target);
        col[x].erase(target);
        sq[y/3*3+x/3].erase(target);
    }

    bool solve(vector<vector<char>>& b, vector<pair<int,int>>& vec, int pos) {
        if(pos == vec.size()) return true;
        auto [y, x] = vec[pos];
        for(char c = '1'; c <= '9'; c++) {
            if(check(y,x,c)) {
                b[y][x] = c;
                add(y,x,c);
                if(solve(b, vec, pos + 1)) return true;
                erase(y,x,c);
                b[y][x] = '.';
            }
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++) {
                if (board[i][j] == '.') vec.push_back({i,j});
                else {
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    sq[i/3*3+j/3].insert(board[i][j]);
                }
            }
        solve(board, vec, 0);
    }
};