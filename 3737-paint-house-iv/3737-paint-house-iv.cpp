class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        vector<vector<long long>> dp(3,vector<long long>(3,0));
        for(int i = 0, j = n - 1; i <= j; i++,j--) {
            vector<vector<long long>> dpp(3,vector<long long>(3,LLONG_MAX));
            for(int x = 0; x < 3; x++) {
                for(int y = 0; y < 3; y++) {
                    if(x == y and i != j) continue;
                    for(int a = 0; a < 3; a++) for(int b = 0; b < 3; b++) {
                        if(a == x) continue;
                        if(b == y) continue;
                        dpp[x][y] = min(dpp[x][y], dp[a][b]);
                    }
                    
                    long long c = (i == j ? cost[i][x] : cost[i][x] + cost[j][y]);
                    dpp[x][y] += c;
                }
            }
            swap(dp,dpp);
        }
        long long res = LLONG_MAX;
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++) res = min(res, dp[i][j]);
        return res;
    }
};