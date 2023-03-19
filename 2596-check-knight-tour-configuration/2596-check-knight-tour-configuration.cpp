class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& A) {
        int dy[8]{-1,-2,-2,-1,1,2,2,1},dx[8]{-2,-1,1,2,2,1,-1,-2};
        int y = 0, x = 0, n = A.size();
        if(A[y][x]) return false;
        for(int i = 0; i < n * n - 1; i++) {
            bool ok = false;
            for(int j = 0; j < 8 and !ok; j++) {
                int ny = y + dy[j], nx = x + dx[j];
                if(0 <= ny and ny < n and 0 <= nx and nx < n) {
                    if(A[y][x] + 1 == A[ny][nx]) {
                        y = ny, x = nx, ok = true;
                    }
                }
            }
            if(!ok) return false;
        } 
        return true;
    }
};
