
int uf[50505];
int find(int u) {
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
bool uni(int u, int v) {
    int pu = find(u), pv = find(v);
    if(pu == pv) return false;
    uf[pu] = uf[pv] = min(pu,pv);
    return true;
}
class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges, int k) {
        if(k == n) return 0;
        sort(begin(edges), end(edges), [](auto& e1, auto& e2) {
            return e1[2] < e2[2];
        });
        iota(begin(uf), end(uf),0);
        int res = 0, commp = n;
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            if(uni(u,v)) {
                res = w;
                commp--;
            }
            if(commp == k) break;
        }
        return res;
    }
};