class Solution {
    vector<vector<int>> distance;
    int dp[11][1<<11];
    
    int dfs(int w, int mask) {
        if(w == distance.size()) return 0;
        if(dp[w][mask] != -1) return dp[w][mask];
        dp[w][mask] = INT_MAX;
        for(int i = 0; i < distance[w].size(); i++) {
            if(mask & (1<<i)) continue;
            dp[w][mask] = min(dp[w][mask], dfs(w + 1, mask | (1<<i)) + distance[w][i]);
        }
        
        return dp[w][mask];
    }
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size(), m = bikes.size();
        memset(dp,-1,sizeof(dp));
        
        distance = vector<vector<int>>(n, vector<int>(m));
        
        for(int i = 0; i < n; i++) { //init distance
            for(int j = 0; j < m; j++) {
                distance[i][j] = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1] - bikes[j][1]);
            }
        }
        
        
        return dfs(0,0);
    }
};