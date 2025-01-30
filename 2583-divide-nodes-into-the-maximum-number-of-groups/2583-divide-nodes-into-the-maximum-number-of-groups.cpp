
int uf[555];
int find(int u) {
    return uf[u] == u ? u : uf[u] = find(uf[u]);
}
void uni(int u, int v) {
    int pu = find(v), pv = find(u);
    uf[pu] = uf[pv] = min(pu, pv);
}
class Solution {
    int dfs1(vector<vector<int>>& adj, vector<int>& sub, int u, int par) {
        for(auto v : adj[u]) {
            if(v == par) continue;
            sub[u] += dfs1(adj,sub,v,u);
        }
        return sub[u] + 1;
    }
    int bfs(vector<vector<int>>& adj, int u, int n) {
        vector<int> dep(n + 1, -1);
        dep[u] = 1;
        queue<int> q;
        q.push(u);
        int res = 1;
        while(q.size()) {
            auto u = q.front(); q.pop();
            for(auto& v : adj[u]) {
                if(dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    res = max(res, dep[v]);
                    q.push(v);
                } else {
                    if(abs(dep[v] - dep[u]) != 1) return -1;
                }
            }
        }
        return res;
    }
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n + 1);
        iota(begin(uf), end(uf),0);
        unordered_set<int> us;
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            uni(u,v);
            us.insert(u);
            us.insert(v);
        }
        int res = 0;
        unordered_map<int, int> mp;
        for(int i = 1; i <= n; i++) {
            int pi = find(i);
            mp[pi] = max(mp[pi], bfs(adj,i,n));
        }
        for(auto [_, v] : mp) {
            if(v == 0) return -1;
            res += v;
        }
        return res;
    }
};