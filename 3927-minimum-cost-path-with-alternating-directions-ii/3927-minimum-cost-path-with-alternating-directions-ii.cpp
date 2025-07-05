class Solution {
public:
    long long minCost(int n, int m, vector<vector<int>>& waitCost) {
        vector<vector<long long>> cost(n, vector<long long>(m, LLONG_MAX));
        cost[0][0] = 1;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            if(i + 1 < n) cost[i+1][j] = min(cost[i+1][j], waitCost[i+1][j] + cost[i][j] + (i + 2ll) * (j + 1ll));
            if(j + 1 < m) cost[i][j+1] = min(cost[i][j+1], waitCost[i][j+1] + cost[i][j] + (i + 1ll) * (j + 2ll));
        }

        return cost[n-1][m-1] - waitCost[n-1][m-1];
    }
};