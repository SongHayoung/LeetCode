
class Solution {
    long long helper(vector<long long>& A, int n) {
        long long res = 0;

        for(int i = 0; i <= n; i++) {
            for(long long j = i, mi = A[j];  j >= 0; j--) {
                mi = min(mi, A[j]);
                res += mi;
            }
        }


        return res;
    }
public:
    long long countSubmatrices(vector<vector<int>>& grid, int k) {
        long long res = 0, n = grid.size(), m = grid[0].size();
        vector<long long> dp(m+1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] <= k) dp[j]++;
                else dp[j] = 0;
            }
            res += helper(dp,m);
        }
        return res;
    }
};