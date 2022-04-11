class NumMatrix {
    vector<vector<int>> matrix;
    int n, m;
    int getOrZero(int y, int x) {
        if(0 <= x and x < m and 0 <= y and y < n) {
            return matrix[y][x];
        }
        return 0;
    }
public:
    NumMatrix(vector<vector<int>>& ma) {
        n = ma.size();
        m = ma[0].size();
        matrix = ma;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                matrix[i][j] += getOrZero(i-1,j) + getOrZero(i,j-1) - getOrZero(i-1,j-1);
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return getOrZero(row2,col2) + getOrZero(row1-1,col1-1)
            - getOrZero(row2,col1-1) - getOrZero(row1-1,col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */