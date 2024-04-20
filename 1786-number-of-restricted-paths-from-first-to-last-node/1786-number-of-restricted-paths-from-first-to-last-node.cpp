class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1] , w = e[2];
            u -= 1 , v -= 1;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> cost(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        auto push = [&](int u, int c) {
            if(cost[u] > c) {
                cost[u] = c;
                q.push({c,u});
            }
        };
        push(n-1,0);
        while(q.size()) {
            auto [c,u] = q.top(); q.pop();
            if(cost[u] != c) continue;
            for(auto& [v,w] : adj[u]) push(v,c + w);
        }
        int mod = 1e9 + 7;
        vector<long> dp(n);
        dp[0] = 1;
        vector<int> ord(n);
        for(int i = 0; i < n; i++) ord[i] = i;
        sort(begin(ord), end(ord), [&](int i, int j) {
            return cost[i] > cost[j];
        });
        for(int i = 0; i < n; i++) {
            int u = ord[i];
            if(!dp[u]) continue;
            for(auto& [v,w] : adj[u]) {
                if(cost[v] >= cost[u]) continue;
                dp[v] = (dp[v] + dp[u]) % mod;
            }
        }
        return dp[n-1];
    }
};