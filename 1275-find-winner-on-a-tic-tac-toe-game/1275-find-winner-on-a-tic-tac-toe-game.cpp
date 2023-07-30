class Solution {
    int dy[8]{-1,-1,-1,0,1,1,1,0}, dx[8]{-1,0,1,1,1,0,-1,-1};
    bool fin(vector<vector<int>>& g) {
        if(g[0][1] != -1) {
            if(g[0][0] == g[0][1] and g[0][1] == g[0][2]) return true;
            if(g[0][1] == g[1][1] and g[1][1] == g[2][1]) return true;
        }
        if(g[1][0] != -1) {
            if(g[0][0] == g[1][0] and g[1][0] == g[2][0]) return true;
        }
        if(g[1][2] != -1) {
            if(g[0][2] == g[1][2] and g[1][2] == g[2][2]) return true;
        }
        if(g[2][1] != -1) {
            if(g[2][0] == g[2][1] and g[2][1] == g[2][2]) return true;
        }
        if(g[1][1] != -1) {
            if(g[1][0] == g[1][1] and g[1][1] == g[1][2]) return true;
            if(g[0][0] == g[1][1] and g[1][1] == g[2][2]) return true;
            if(g[0][2] == g[1][1] and g[1][1] == g[2][0]) return true;
        }
        return false;
    }
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> grid(3,vector<int>(3,-1));
        bool fl = 0;
        for(auto m : moves) {
            grid[m[0]][m[1]] = fl;
            if(fin(grid)) return fl ? "B" : "A";
            fl = !fl;
        }
        return moves.size() != 9 ? "Pending" : "Draw";
    }
};