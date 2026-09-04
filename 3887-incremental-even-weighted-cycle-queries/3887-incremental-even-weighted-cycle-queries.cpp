
long long uf[50505];
int cost[50505];
long long find(int u) {
     if (uf[u] == u) return u;
        int p = uf[u];
        uf[u] = find(p);
        cost[u] ^= cost[p];
        return uf[u];
}
bool uni(int u, int v, int c) {
    int pu = find(u), pv = find(v);
    int cu = cost[u], cv = cost[v];
    if(pu == pv) return !(cu ^ cv ^ c);
    uf[pv] = pu;
    cost[pv] = cu ^ cv ^ c;
    return true;
}
class Solution {
public:
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        iota(begin(uf), end(uf),0);
        memset(cost, 0, sizeof cost);
        int res = 0;
        for(auto& e : edges) {
            if(uni(e[0],e[1],e[2])) res++;
        }
        return res;
    }
};