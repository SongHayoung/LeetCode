class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int n = ob.size(), m = ob[0].size();
        if(ob[0][0] == 1 or ob[n-1][m-1] == 1) return 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(ob[i][j] == 1) ob[i][j] = -1;
        }
        for(int i = 0; i < m and ob[0][i] == 0; i++) ob[0][i] = 1;
        for(int i = 1; i < n and ob[i][0] == 0; i++) ob[i][0] = 1;
        
        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(ob[i][j] == -1) continue;
                ob[i][j] = (ob[i-1][j] == -1 ? 0 : ob[i-1][j]) + (ob[i][j-1] == -1 ? 0 : ob[i][j-1]);
            }
        }
       return ob[n-1][m-1]; 
    }
};