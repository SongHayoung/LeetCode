class Solution {
    int uf[111];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
    bool intersect(bitset<100>& A, bitset<100>& B, int k) {
        return (A & B).count() >= k;
    }
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        iota(begin(uf), end(uf), 0);
        int n = properties.size(), res = 0;
        vector<bitset<100>> bs(properties.size());
        for(int i = 0; i < n; i++) {
            for(auto& p : properties[i]) bs[i][p-1] = 1;
        }
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(intersect(bs[i], bs[j], k)) uni(i,j);
            }
        }
        for(int i = 0; i < n; i++) if(find(i) == i) res++;
        return res;
    }
};