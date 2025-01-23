class Solution {
public:
    int countServers(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        unordered_map<int, vector<int>> row;
        unordered_map<int, vector<int>> col;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(A[i][j]) {
                    row[i].push_back(j);
                    col[j].push_back(i);
                }
            }
        }
        int res = 0;
        for(auto& [y, vx] : row) {
            if(vx.size() == 1) continue;
            for(auto& x : vx) {
                res += A[y][x];
                A[y][x] = 0;
            }
        }
        for(auto& [x, vy] : col) {
            if(vy.size() == 1) continue;
            for(auto& y : vy) {
                res += A[y][x];
                A[y][x] = 0;
            }
        }
        return res;
    }
};