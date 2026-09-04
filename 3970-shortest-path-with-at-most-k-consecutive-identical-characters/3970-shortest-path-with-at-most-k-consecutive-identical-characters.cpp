
int dp[50505][55];
class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        memset(dp,-1,sizeof dp);
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
        }
        priority_queue<array<int,3>,vector<array<int,3>>, greater<>> q;
        auto push = [&](int u, int w, int t) {
            if(t == k) return;
            if(dp[u][t] != -1 and dp[u][t] <= w) return;
            dp[u][t] = w;
            q.push({w,u,t});
        };
        push(0,0,0);
        while(q.size()) {
            auto [w,u,t] = q.top(); q.pop();
            if(dp[u][t] != w) continue;
            for(auto& [v,c] : adj[u]) {
                push(v,w+c, labels[u] == labels[v] ? t + 1 : 0);
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < k; i++) if(dp[n-1][i] != -1) res = min(res, dp[n-1][i]);
        return res == INT_MAX ? -1 : res;
    }
};