class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        for(int i = 0; i < m; i++) {
            int y = 0, x = i;
            while(y + 1 < n and x + 1 < m) {
                if(matrix[y][x] != matrix[y+1][x+1]) return false;
                y++,x++;
            }
        }
        for(int i = 1; i < n; i++) {
            int y = i, x = 0;
            while(y + 1 < n and x + 1 < m) {
                if(matrix[y][x] != matrix[y+1][x+1]) return false;
                y++,x++;
            }
        }
        return true;
    }
};