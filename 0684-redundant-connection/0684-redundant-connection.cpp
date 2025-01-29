class Solution {
    unordered_map<int, int> g;
    int find(int n) {
        if(g.count(n)) return __find(n);
        return g[n] = n;
    }
    int __find(int n) {
        return g[n] == n ? n : g[n] = __find(g[n]);
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        for(auto e : edges) {
            int pa = find(e[0]), pb = find(e[1]);
            if(pa == pb) return e;
            g[pa] = g[pb] = min(pa, pb);
        }
        
        return {};
    }
};