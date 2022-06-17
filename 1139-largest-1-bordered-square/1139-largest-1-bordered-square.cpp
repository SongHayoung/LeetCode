class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cpsum(n, vector<int>(m));
        vector<vector<int>> rpsum(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cpsum[i][j] = (j ? cpsum[i][j - 1] + grid[i][j] : grid[i][j]);
                rpsum[i][j] = (i ? rpsum[i-1][j] + grid[i][j] : grid[i][j]);
            }
        }
        int res = 0;
        for(int i = 0; i < n - res; i++) {
            for(int j = 0; j < m - res; j++) {
                if(!grid[i][j]) continue;
                for(int now = res; i + now < n and j + now < m; now++) {
                    int l1 = cpsum[i][j+now] - (j - 1 >= 0 ? cpsum[i][j-1] : 0);
                    int l2 = cpsum[i+now][j+now] - (j - 1 >= 0 ? cpsum[i+now][j-1] : 0);
                    int l3 = rpsum[i+now][j] - (i - 1 >= 0 ? rpsum[i-1][j] : 0);
                    int l4 = rpsum[i+now][j+now] - (i - 1 >= 0 ? rpsum[i-1][j+now] : 0);
                    if(l1 == l2 and l2 == l3 and l3 == l4 and l4 == now + 1) {
                        res = max(res, now + 1);
                    }
                }
            }
        }
        return res * res;
    }
};