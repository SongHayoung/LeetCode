class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for(auto r : roads) {
            int u = r[0], v = r[1], w = r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> vis(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({INT_MAX, 1});
        while(q.size()) {
            auto [w,u] = q.top(); q.pop();
            if(vis[u] != w) continue;
            for(auto [v,c] : adj[u]) {
                int cost = min(c,vis[u]);
                if(vis[v] > cost) {
                    vis[v] = cost;
                    q.push({cost,v});
                }
            }
        }
        if(vis[n] == INT_MAX) return -1;
        return vis[n];
    }
};
