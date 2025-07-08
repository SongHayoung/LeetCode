class Solution {
    int uf[101010];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    bool uni(int u, int v) {
        int pu = find(u), pv = find(v);
        if(pu == pv) return false;
        uf[pu] = uf[pv] = min(pu,pv);
        return true;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
        if(edges.size() == 0) return 0;
        sort(begin(edges), end(edges), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        iota(begin(uf), end(uf), 0);
        int comp = n;
        while(edges.size()) {
            int x = edges.back()[2];
            while(edges.size() and edges.back()[2] == x) {
                int u = edges.back()[0], v = edges.back()[1], t = edges.back()[2];
                edges.pop_back();
                comp -= uni(u,v);
            }
            if(comp < k) return x;
        }
        return 0;
    }
};