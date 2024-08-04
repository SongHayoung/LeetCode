class neighborSum {
    vector<vector<int>> A;
public:
    neighborSum(vector<vector<int>>& grid) {
        A = grid;
    }

    int helper(int x, vector<int>& dy, vector<int>& dx) {
        int res = 0;
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size(); j++) {
                if(A[i][j] != x) continue;
                for(int k = 0; k < 4; k++) {
                    int ny = i + dy[k], nx = j + dx[k];
                    if(0 <= ny and ny < A.size() and 0 <= nx and nx < A[0].size()) {
                        res += A[ny][nx];
                    }
                }
            }
        }
        return res;
    }
    
    int adjacentSum(int value) {
        vector<int> dy{-1,0,1,0}, dx{0,-1,0,1};
        return helper(value, dy, dx);
    }
    
    int diagonalSum(int value) {
        vector<int> dy{-1,-1,1,1}, dx{-1,1,-1,1};
        return helper(value, dy, dx);
    }
};

/**
 * Your neighborSum object will be instantiated and called as such:
 * neighborSum* obj = new neighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */