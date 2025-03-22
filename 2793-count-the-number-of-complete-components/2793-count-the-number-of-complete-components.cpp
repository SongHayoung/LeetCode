
class Solution {
    int uf[101];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu ] = uf[pv] = min(pu,pv);
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) uf[i] = i;
        unordered_set<int> adj[n];
        for(auto e : edges) {
            int u = e[0], v = e[1];
            uni(u,v);
            adj[u].insert(v);
            adj[v].insert(u);
        }
        unordered_map<int, vector<int>> g;
        for(int i = 0; i < n; i++) {
            g[find(i)].push_back(i);
        }
        int res = 0;
        for(auto [k, vec] : g) {
            bool ok = true;
            for(int i = 0; i < vec.size() and ok; i++) {
                for(int j = i + 1; j < vec.size() and ok; j++) {
                    if(!adj[vec[i]].count(vec[j])) ok = false;
                }
            }
            res += ok;
        }
        return res;
    }
};