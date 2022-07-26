class Solution {
    int uf[20202] = {};
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    int largestComponentSize(vector<int>& A) {
        iota(begin(uf),end(uf),0);
        int res = 0, n = A.size();
        vector<int> mp(101010, -1);
        for(int i = 0; i < n; i++) {
            for(int j = 2; j * j <= A[i]; j++) {
                if(A[i] % j) continue;
                while(!(A[i] % j)) {
                    A[i] /= j;
                }
                if(mp[j] == -1) mp[j] = i;
                else uni(i,mp[j]);
            }
            if(A[i] != 1) {
                if(mp[A[i]] == -1) mp[A[i]] = i;
                else uni(i,mp[A[i]]);
            }
        }
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) {
            res = max(res, ++freq[find(i)]);
        }
        return res;
    }
};