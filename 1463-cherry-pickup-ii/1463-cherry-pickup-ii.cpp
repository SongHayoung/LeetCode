class Solution {
    int dp[70][70][70];
    int solution(vector<vector<int>>& g, int row, int x1, int x2) {
        if(row == g.size()) return 0;
        if(dp[row][x1][x2] != -1) return dp[row][x1][x2];
        int &res = dp[row][x1][x2];
        int m = g[row].size();
        vector<int> nx1s{x1-1,x1,x1+1};
        vector<int> nx2s{x2-1,x2,x2+1};
        for(auto nx1 : nx1s) {
            for(auto nx2: nx2s) {
                if(0 <= nx1 and nx1 < m and 0 <= nx2 and nx2 < m and nx1 < nx2) {
                    res = max(res, solution(g,row+1,nx1,nx2));
                }
            }
        }
        res += g[row][x1] + g[row][x2];
        return res;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        return solution(grid,0,0,grid[0].size()-1);
    }
};