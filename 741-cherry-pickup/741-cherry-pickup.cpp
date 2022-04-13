class Solution {
    int dp[51][51][51];
    int N;
    bool inRange(int y, int x) {
        return 0 <= y and y < N and 0 <= x and x < N;
    }
    int helper(int y1, int x1, int x2, vector<vector<int>>& g) {
        int y2 = y1 + x1 - x2;
        
        if(!inRange(y1,x1) or !inRange(y2,x2) or g[y1][x1] == -1 or g[y2][x2] == -1) return INT_MIN;
        
        if(y1 == N - 1 and x1 == N - 1) return g.back().back();
        
        if(dp[y1][x1][x2] != -1) return dp[y1][x1][x2];
        
        return dp[y1][x1][x2] = max({
            helper(y1+1, x1, x2+1, g), 
            helper(y1+1, x1, x2, g), 
            helper(y1, x1+1, x2, g), 
            helper(y1, x1+1, x2+1, g)
        }) + g[y1][x1] + (x1 != x2 ? g[y2][x2] : 0);;
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        N = grid.size();
        return max(0, helper(0,0,0,grid));
    }
};