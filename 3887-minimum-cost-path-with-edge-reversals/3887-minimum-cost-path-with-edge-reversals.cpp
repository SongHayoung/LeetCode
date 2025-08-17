class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<long long> vis(n, INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<pair<long long, long long>,vector<pair<long long, long long>>, greater<>> q;
        auto push = [&](long long u, long long c) {
            if(vis[u] > c) {
                vis[u] = c;
                q.push({c,u});
            }
        };
        for(auto& e : edges) {
            long long u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w*2});
        }
        push(0,0);
        while(q.size()) {
            auto [c,u] = q.top(); q.pop();
            if(vis[u] != c) continue;
            for(auto& [v,w] : adj[u]) push(v,c + w);
        }
        return vis[n-1] == INT_MAX ? -1 : vis[n-1];
    }
};