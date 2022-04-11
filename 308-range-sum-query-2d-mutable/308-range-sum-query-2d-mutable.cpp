class NumMatrix {
    vector<vector<int>> ma;
    vector<vector<int>> origin;
    int n, m;
    map<int, map<int,int>> diff;
    int getOrZero(int y, int x) {
        if(0<=y and y<n and 0<=x and x<m)
            return ma[y][x];
        return 0;
    }
    int getDiff(int row1, int col1, int row2, int col2) {
        int res = 0;
        for(auto y = diff.lower_bound(row1); y != diff.end() and y->first <= row2; y++) {
            for(auto x = y->second.lower_bound(col1); x != y->second.end() and x->first <= col2; x++) {
                res += x->second - origin[y->first][x->first];
            }
        }
        return res;
    }
public:
    NumMatrix(vector<vector<int>>& matrix) {
        ma = origin = matrix;
        n = ma.size(), m = ma[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ma[i][j] += getOrZero(i-1,j) + getOrZero(i,j-1) - getOrZero(i-1,j-1);
            }
        }
    }

    void update(int row, int col, int val) {
        diff[row][col] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return ma[row2][col2] - getOrZero(row2, col1-1) - getOrZero(row1-1, col2) + getOrZero(row1-1, col1-1) + getDiff(row1,col1,row2,col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */