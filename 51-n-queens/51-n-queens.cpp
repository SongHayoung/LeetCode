class Solution {
    vector<vector<string>> res;
    int queen = 0;
    bool isPossible(vector<string>& b, int y, int x, int n) {
        int bx = x, ax = x;
        while(y--) {
            bx--, ax++;
            if(bx >= 0 && b[y][bx] == 'Q') return false;
            if(ax < n && b[y][ax] == 'Q') return false;
        }
        return true;
    }
    void dfs(int cur, int n, vector<string>& b) {
        if(cur == n) {
            res.push_back(b);
            return;
        }
        for(int i = 0; i < n; i++) {
            if((queen & (1<<i)) || !isPossible(b, cur, i, n)) continue;
            queen ^= (1<<i);
            b[cur][i] = 'Q';
            dfs(cur + 1, n, b);
            b[cur][i] = '.';
            queen ^= (1<<i);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        dfs(0, n, board);
        return res;
    }
};
