class Solution {
    vector<int> adj[1010];
    int dep[1010], par[1010];
    long long bfs(int u) {
        memset(dep, -1, sizeof dep);
        memset(par, -1, sizeof par);
        dep[u] = 0;
        long long res = INT_MAX;
        queue<int> q;
        q.push(u);
        while(q.size()) {
            int u = q.front();
            q.pop();
            for (auto &v: adj[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    par[v] = u;
                    q.push(v);
                } else if(par[u] != v and par[v] != u) {
                    res = min(res, dep[u] + dep[v] + 1ll);
                }
            }
        }
        return res;
    }
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) adj[i].clear();
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        long long res = INT_MAX;
        for(int i = 0; i < n; i++) {
            if(adj[i].size() == 1) continue;
            res = min(res, bfs(i));
        }
        return res == INT_MAX ? -1 : res;
    }
};