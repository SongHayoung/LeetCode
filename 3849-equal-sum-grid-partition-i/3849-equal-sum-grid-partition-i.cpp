class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long n = grid.size(), m = grid[0].size(), sum = 0;
        vector<long long> row(n), col(m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                sum += grid[i][j];
                row[i] += grid[i][j];
                col[j] += grid[i][j];
            }
        }
        auto check = [&](vector<long long>& pre) {
            for(int i = 0; i < pre.size() - 1; i++) {
                if(i) pre[i] += pre[i-1];
                if(pre[i] * 2 == sum) return true;
                if(pre[i] * 2 > sum) break;
            }
            return false;
        };
        return !(sum & 1) and (check(row) or check(col));
    }
};