class Solution {
    int dp[100000];
    int dfs(int id, vector<int>& manager, vector<int>& informTime) {
        if(dp[id] != -1) return dp[id];
        return dp[id] = dfs(manager[id], manager, informTime) + informTime[manager[id]];
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n == 1) return 0;
        memset(dp, -1, sizeof(dp));
        dp[headID] = 0;
        int res = 0;
        for(int i = 0; i < n; i++) {
            res = max(res, dfs(i,manager,informTime));
        }
        return res;
    }
};