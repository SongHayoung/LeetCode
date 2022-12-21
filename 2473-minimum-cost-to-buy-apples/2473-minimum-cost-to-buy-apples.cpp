class Solution {
    long long bfs(vector<vector<pair<long long, long long>>>& adj, int start, int n, vector<int>& apple, int k) {
        long long res = apple[start];
        vector<long long> cost(n,1e18);
        cost[start] = 0;
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> q;
        q.push({0,start});
        while(q.size() and q.top().first < res) {
            auto [c,u] = q.top(); q.pop();
            if(cost[u] != c) continue;
            if(u != start) res = min(res, cost[u] * (k + 1) + apple[u]);
            for(auto& [v,w] : adj[u]) {
                if(cost[v] > cost[u] + w) {
                    cost[v] = cost[u] + w;
                    q.push({cost[v], v});
                }
            }
        }
        return res;
    }
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        vector<long long> res;
        vector<vector<pair<long long, long long>>> adj(n);
        for(auto r : roads) {
            int u = r[0] - 1, v = r[1] - 1, w = r[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        for(int i = 0; i < n; i++) {
            res.push_back(bfs(adj,i,n,appleCost,k));
        }
        return res;
    }
};