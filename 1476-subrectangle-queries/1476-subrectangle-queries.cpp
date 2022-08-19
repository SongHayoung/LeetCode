class SubrectangleQueries {
    vector<vector<int>> rec;
    vector<vector<int>> his;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        rec = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        his.push_back({row1, col1, row2, col2, newValue});
    }
    
    int getValue(int row, int col) {
        for(int i = his.size() - 1; i >= 0; i--) {
            int r1 = his[i][0], c1 = his[i][1], r2 = his[i][2], c2 = his[i][3], v = his[i][4];
            if(r1 <= row and row <= r2 and c1 <= col and col <= c2) return v;
        }
        return rec[row][col];
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */