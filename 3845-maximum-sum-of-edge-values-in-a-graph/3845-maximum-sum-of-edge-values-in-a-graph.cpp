class Solution {
    vector<int> vis;
    vector<int> vals;
    vector<vector<int>> adj;
    int id;
    array<int,3> dfs(int u, int par) {
        if(vis[u]) return {2,0,u};
        vis[u] = 1;
        if(adj[u].size() == 0) return {0,1,u};
        for(auto& v : adj[u]) {
            if(v == par) continue;
            auto [tp, cnt, tail] = dfs(v,u);
            return {tp, cnt + 1, tail};
        }
        return {1,1,u};
    }
    void helper(int tp, int u1, int u2) {
        if(tp == 0) vals[u1] = id++;
        else {
            queue<int> q;
            auto push = [&](int u) {
                if(vals[u] == 0) {
                    vals[u] = id++;
                    q.push(u);
                }
            };
            push(u1);
            push(u2);
            while(q.size()) {
                auto u = q.front(); q.pop();
                for(auto& v : adj[u]) push(v);
            }
        }
    }
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        map<int,map<int,vector<pair<int,int>>>> graphs;
        adj = vector<vector<int>>(n);
        vals = vis = vector<int>(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            if(adj[i].size() < 2) {
                auto [type, nodes, tail] = dfs(i,-1);
                graphs[type][nodes].push_back({i,tail});
            }
        }
        for(int i = 0; i < n; i++) if(!vis[i]) {
            auto [type, nodes, tail] = dfs(i,-1);
            graphs[type][nodes].push_back({i,tail});
        }
        long long res = 0;
        id = 1;
        for(auto& [tp, tpg] : graphs) {
            for(auto& [cnt, roots] : tpg) {
                for(auto& [root1, root2] : roots) helper(tp, root1, root2);
            }
        }
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            res += 1ll * vals[u] * vals[v];
        }
        return res;
    }
};