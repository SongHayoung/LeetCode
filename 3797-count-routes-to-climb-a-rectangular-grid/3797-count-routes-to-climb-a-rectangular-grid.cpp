long long mod = 1e9 + 7;

class Solution {
    int helper(int d) {
        long long l = 1, r = d, res = 0;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = (1 + m * m) <= d * d;
            if(ok) {
                res = m;
                l = m + 1;
            } else r = m - 1;
        }
        return res;
    }
public:
    int numberOfRoutes(vector<string>& grid, int d) {
        int n = grid.size(), m = grid[0].size(), d2 = helper(d);
        vector<long long> dp(m);
        for(int j = 0; j < m; j++) if(grid[n-1][j] == '.') dp[j] = 1;
        auto genPrefixSum = [](vector<long long>& A) {
            vector<long long> preSum(A.size() + 1);
            for(int j = 0; j < A.size(); j++) preSum[j+1] = (preSum[j] + A[j]) % mod;
            return preSum;
        };
        auto qry = [](vector<long long>& preSum, int l, int r) {
            int n = preSum.size();
            return (preSum[min(r+1,n - 1)] - preSum[max(0,l)] + mod) % mod;
        };
        for(int i = n - 1; i >= 0; i--) {
            vector<long long> preSum = genPrefixSum(dp);
            vector<long long> dpp(m);
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '.') {
                    dpp[j] = qry(preSum, j - d, j + d);
                }
            }
            if(i == 0) {
                long long res = 0;
                for(int j = 0; j < m; j++) res = (res + dpp[j]) % mod;
                return res;
            }
            vector<long long> accPreSum = genPrefixSum(dpp);
            vector<long long> dppp(m);
            for(int j = 0; j < m; j++) {
                if(grid[i-1][j] == '.') {
                    dppp[j] = qry(accPreSum, j - d2, j + d2);
                }
            }
            swap(dp,dppp);
        }
        return -1;
    }
};

