class Solution {
    vector<int> uf;
    int find(int u) {
        return uf[u] == u? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu, pv);
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        uf = vector<int>(n);
        for(int i = 0; i < n; i++) uf[i] = i;
        unordered_map<int, int> freq;
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            uni(u, v);
        }
        
        for(int i = 0; i < n; i++) {
            freq[find(i)]++;
        }
        
        long long res = 0;
        
        for(int i = 0; i < n; i++) {
            int c = freq[find(i)];
            res += n - c;
        }
        
        return res / 2;
    }
};