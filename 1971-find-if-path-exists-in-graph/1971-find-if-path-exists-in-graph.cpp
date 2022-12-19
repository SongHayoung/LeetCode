class Solution {
    int uf[202020];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu, pv);
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        iota(begin(uf), end(uf), 0);
        for(auto e : edges) {
            uni(e[0], e[1]);
        }
        return find(source) == find(destination);
    }
};