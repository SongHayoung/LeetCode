int id = 0, gap = 1e5;
pair<int,int> freq[202020];
class Solution {
    vector<vector<int>> rotate(vector<vector<int>>& A) {
        int n = A.size(), m = A[0].size();
        vector<vector<int>> res(m, vector<int>(n));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                res[j][n - 1 - i] = A[i][j];

        return res;
    }
    void update(int x, int op) {
        x += gap;
        if(freq[x].first != id) freq[x] = {id, 0};
        freq[x].second += op;
    }
    bool ok(vector<vector<int>>& A, long long sum) {
        long long n = A.size(), m = A[0].size(), cur = 0;
        if(n == 1) return false;
        if(m == 1) {
            for(int i = 0; i < n - 1; i++) {
                cur += A[i][0];
                long long oth = sum - cur;
                if(oth == cur) return true;
                if(cur - A[0][0] == oth) return true;
                if(cur - A[i][0] == oth) return true;
                if(cur == oth - A[i+1][0]) return true;
                if(cur == oth - A[n-1][0]) return true;
            }
            return false;
        }
        auto has = [&](long long x) {
            if(x < -1e5 or x > 1e5) return false;
            x += gap;
            return freq[x].first == id and freq[x].second > 0;
        };
        id++;
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) update(-A[i][j], 1);
        for(int i = 0; i < n - 1; i++) {
            for(int j = 0; j < m; j++) {
                cur += A[i][j];
                update(-A[i][j], -1);
            }
            if(i == 0) {
                update(A[0][0], 1);
                update(A[0][m-1], 1);
            } else if(i >= 1) {
                for(int j = 0; j < m; j++) update(A[i][j], 1);
                if(i == 1) {
                    for(int j = 1; j < m - 1; j++) update(A[i-1][j], 1);
                }
            }

            if(i + 1 == n - 1) {
                for(int j = 1; j < m - 1; j++) update(-A[i+1][j], -1);
            }

            long long oth = sum - cur;
            if(cur == oth or has(cur-oth)) return true;
            if(cur - oth > 1e5) return false;
        }
        return false;
    }
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long sum = 0;
        for(auto& r : grid) for(auto& c : r) sum += c;
        if(ok(grid, sum)) return true;
        grid = rotate(grid);
        return ok(grid, sum);
    }
};