class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& A) {
        long long mod = 12345, mul = 1;
        int n = A.size(), m = A[0].size();
        if(n == 1 and m == 1) return {{0}};
        vector<long long> pre(n), suf(n);
        vector<long long> row(n,1);
        for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
            row[i] = row[i] * A[i][j] % mod;
        }
        pre[0] = row[0];
        for(int i = 1; i < n; i++) pre[i] = pre[i-1] * row[i] % mod;
        suf[n-1] = row[n-1];
        for(int i = n - 2; i >= 0; i--) suf[i] = suf[i+1] * row[i] % mod;
        vector<vector<int>> res(n, vector<int>(m));
        for(int i = 0; i < n; i++) {
            long long base = (i ? pre[i-1] : 1ll) * (i + 1 < n ? suf[i+1] : 1ll) % mod;
            vector<long long> pre(m,A[i].front()), suf(m, A[i].back());
            for(int j = 1; j < m; j++) {
                pre[j] = pre[j-1] * A[i][j] % mod;
            }
            for(int j = m - 2; j >= 0; j--) {
                suf[j] = suf[j+1] * A[i][j] % mod;
            }
            for(int j = 0; j < m; j++) {
                res[i][j] = base * (j ? pre[j-1] : 1ll) % mod * (j + 1 < m ? suf[j+1] : 1ll) % mod;
            }
        }
        return res;
    }
};