class Solution {
public:
    int minimumDistance(int n, vector<vector<int>>& edges, int s, vector<int>& marked) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
        }
        vector<long long> cost(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        auto push = [&](int u, int c) {
            if(cost[u] > c) {
                cost[u] = c;
                q.push({c,u});
            }
        };
        push(s,0);
        long long res = INT_MAX;
        unordered_set<int> us(begin(marked), end(marked));
        while(q.size()) {
            auto [c,u] = q.top(); q.pop();
            if(cost[u] != c) continue;
            if(us.count(u)) res = min(res, cost[u]);
            for(auto& [v,w] : adj[u]) {
                push(v,c + w);
            }
        }
        return res >= INT_MAX ? -1 : res;
    }
};