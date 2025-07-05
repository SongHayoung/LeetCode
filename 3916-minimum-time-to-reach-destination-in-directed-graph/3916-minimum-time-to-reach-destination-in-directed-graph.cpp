class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        vector<int> cost(n, INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> q;
        vector<vector<array<int,3>>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], f = e[2], t = e[3];
            adj[u].push_back({v,f,t});
        }
        auto push = [&](int u, int c) {
            if(cost[u] > c) {
                cost[u] = c;
                q.push({cost[u], u});
            }
        };
        push(0,0);
        while(q.size()) {
            auto [c,u] = q.top(); q.pop();
            if(cost[u] != c) continue;
            for(auto& [v,f,t] : adj[u]) {
                if(cost[u] <= t) push(v,max(f,c)+1);
            }
        }
        return cost[n-1] == INT_MAX ? -1 : cost[n-1];
    }
};