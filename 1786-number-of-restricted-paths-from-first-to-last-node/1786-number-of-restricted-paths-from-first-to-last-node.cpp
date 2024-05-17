class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            u -= 1, v -= 1;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> D(n,INT_MAX);
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
            auto push = [&](int u, int c) {
                if(D[u] > c) {
                    D[u] = c;
                    q.push({c,u});
                }
            };
            push(n-1,0);
            while(q.size()) {
                auto [c,u] = q.top(); q.pop();
                if(D[u] != c) continue;
                for(auto& [v,w] : adj[u]) {
                    push(v,w+c);
                }
            }
        }
        long long mod = 1e9 + 7;
        vector<long long> dp(n);
        dp[0] = 1;
        vector<pair<int,int>> ord;
        for(int i = 0; i < n; i++) {
            ord.push_back({D[i],i});
        }
        sort(rbegin(ord), rend(ord));
        for(auto& [_,u] : ord) {
            if(!dp[u]) continue;
            for(auto& [v,_] : adj[u]) {
                if(D[v] >= D[u]) continue;
                dp[v] = (dp[v] + dp[u]) % mod;
            }
        }
        
        
        return dp[n-1];
    }
};