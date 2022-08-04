class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<int>> vis(n, vector<int>(discounts + 1, INT_MAX));
        vis[0][discounts] = 0;
        vector<vector<pair<int, int>>> adj(n);
        for(auto& h : highways) {
            int u = h[0], v = h[1], c = h[2];
            adj[u].push_back({v,c});
            adj[v].push_back({u,c});
        }
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> q;
        q.push({0,discounts,0});
        while(!q.empty()) {
            auto [cost, dis, u] = q.top(); q.pop();
            if(vis[u][dis] != cost) continue;
            
            for(auto [v, c] : adj[u]) {
                if(vis[v][dis] > cost + c) {
                    vis[v][dis] = cost + c;
                    q.push({cost + c, dis, v});
                }
                if(dis and vis[v][dis-1] > cost + c / 2) {
                    vis[v][dis-1] = cost + c / 2;
                    q.push({cost + c / 2, dis - 1, v});
                }
            }
        }
        int res = *min_element(begin(vis[n-1]), end(vis[n-1]));
        return res == INT_MAX ? -1 : res;
    }
};