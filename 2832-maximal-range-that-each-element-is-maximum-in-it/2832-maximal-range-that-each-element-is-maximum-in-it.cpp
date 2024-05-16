class Solution {
    int uf[101010], cnt[101010];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return;
        cnt[pu] = cnt[pv] = cnt[pu] + cnt[pv];
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    vector<int> maximumLengthOfRanges(vector<int>& A) {
        vector<int> ord(A.size());
        for(int i = 0; i < A.size(); i++) {
            ord[i] = uf[i] = i;
            cnt[i] = 1;
        }
        sort(begin(ord), end(ord), [&](int i, int j) {
            return A[i] < A[j];
        });
        vector<int> res(ord.size());
        for(int i = 0; i < A.size(); i++) {
            int x = ord[i];
            int le = x - 1, ri = x + 1;
            if(0 <= le and le < A.size() and A[le] <= A[x]) uni(le,x);
            if(0 <= ri and ri < A.size() and A[ri] <= A[x]) uni(ri,x);
            res[x] = cnt[find(x)];
        }
        return res;
    }
};