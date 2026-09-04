
int uf[101010];
int find(int u) {
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(u), pv = find(v);
    uf[pu] = uf[pv] = min(pu,pv);
}
class Solution {
    bool helper(int n, vector<vector<int>>& E, int u, int v, int k, int m) {
        iota(begin(uf), end(uf), 0);
        vector<vector<int>> adj(n);
        for(auto& e : E) {
            if(e[2] <= m) uni(e[0],e[1]);
            else {
                int u = find(e[0]), v = find(e[1]);
                if(u == v) continue;
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }
        vector<bool> vis(n);
        queue<int> q;
        auto push = [&](int u) {
            if(!vis[u]) q.push(u), vis[u] = true;
        };
        push(find(u));
        for(int i = 0; i < k; i++) {
            int qsz = q.size();
            while(qsz--) {
                int u = q.front(); q.pop();
                for(auto& v : adj[u]) push(v);
            }
        }
        
        return vis[find(v)];
    }
public:
    int minimumThreshold(int n, vector<vector<int>>& edges, int source, int target, int k) {
        if(source == target) return 0;
        iota(begin(uf), end(uf), 0);
        for(auto& e : edges) uni(e[0], e[1]);
        if(find(source) != find(target)) return -1;
        sort(begin(edges), end(edges), [](auto& a, auto& b) {
            return a[2] < b[2];
        });
        vector<int> S{0};
        for(auto& e : edges) if(S.size() == 0 or S.back() != e[2]) S.push_back(e[2]);
        int l = 0, r = S.size() - 2, res = S.back();
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(n, edges,source,target,k,S[m]);
            if(ok) {
                res = S[m];
                r = m - 1;
            } else l = m + 1;
        }
        return res;
    }
};