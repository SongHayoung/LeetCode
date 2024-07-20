class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& r, vector<int>& c) {
        int n = r.size(), m = c.size();
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            for(int j = 0, now = r[i]; j < m and r[i]; j++) {
                int mi = min(now, c[j]);
                res[i][j] += mi;
                now -= mi;
                c[j] -= mi;
            }
        }
        return res;
    }
};