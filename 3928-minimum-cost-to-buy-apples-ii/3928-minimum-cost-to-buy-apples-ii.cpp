class Solution {
    int helper(int n, vector<int>& prices, vector<vector<array<long long,2>>>& adj, int start) {
        long long res = LLONG_MAX;
        vector<long long> cost(2 * n, INT_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
        auto push = [&](long long idx, long long c) {
            if(cost[idx] > c and c < res) {
                cost[idx] = c;
                q.push({c,idx});
                long long a = idx >= n ? idx - n : idx, b = a + n;
                res = min(res, cost[a] + cost[b] + prices[a]);
            }
        };
        push(start, 0);
        push(start + n, 0);
        while(q.size()) {
            auto [c, u] = q.top(); q.pop();
            if(cost[u] != c) continue;
            for(auto& [v,w] : adj[u]) push(v, c + w);
        }
        return res;
    }
public:
    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {
        vector<vector<array<long long,2>>> adj(2 * n);
        for(auto& r : roads) {
            long long u = r[0], v = r[1], w = r[2], m = r[3];
            adj[u].push_back({v,w});
            adj[u+n].push_back({v+n,w*m});
            adj[v].push_back({u,w});
            adj[v+n].push_back({u+n,w*m});
        }
        vector<int> res;
        for(int i = 0; i < n; i++) res.push_back(helper(n,prices,adj,i));
        return res;
    }
};
