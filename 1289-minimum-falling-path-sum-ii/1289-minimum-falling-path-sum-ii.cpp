class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if(n == 1) return grid[0][0];
        pair<int,int> min1 = {0,INT_MAX}, min2 = {0,INT_MAX};
        for(int i = 0; i < n; i++) {
            pair<int,int> nxtmi1 = {INT_MAX,0}, nxtmi2 = {INT_MAX,0};
            for(int j = 0; j < m; j++) {
                pair<int,int> cur = {grid[i][j] + (min1.second != j?min1.first : min2.first), j};
                if(cur.first < nxtmi1.first) {
                    nxtmi2 = nxtmi1;
                    nxtmi1 = cur;
                } else if(cur.first < nxtmi2.first) {
                    nxtmi2 = cur;
                }
            }
            min1 = nxtmi1;
            min2 = nxtmi2;
        }
        return min1.first;
    }
};