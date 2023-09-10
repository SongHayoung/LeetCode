
class Solution {
    int dp[1<<9];
    int helper(vector<pair<int,int>>& Z, vector<pair<int,int>>& O, int mask, int p) {
        if(p == O.size()) return 0;
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = 101010;
        for(int i = 0; i < Z.size(); i++) {
            if((mask >> i) & 1) continue;
            int dis = abs(Z[i].first- O[p].first) + abs(Z[i].second - O[p].second);
            res = min(res, dis + helper(Z,O,mask | (1ll<<i), p + 1));
        }
        return res;
    }
public:
    int minimumMoves(vector<vector<int>>& grid) {
        int res = 0;
        memset(dp,-1,sizeof dp);
        vector<pair<int,int>> zero, over;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) {
            if(grid[i][j] == 0) zero.push_back({i,j});
            else if(grid[i][j] > 1) {
                for(int k = 1; k < grid[i][j]; k++) over.push_back({i,j});
            }
        }
        return helper(zero,over,0,0);;
    }
};