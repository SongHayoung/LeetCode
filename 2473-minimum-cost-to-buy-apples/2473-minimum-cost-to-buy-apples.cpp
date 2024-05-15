class Solution {
    vector<vector<pair<long long, long long>>> adj; 
    long long helper(vector<int>& C, int u) {
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
        long long res = 1e18;
        vector<long long> D(C.size(), 1e18);
        auto push = [&](long long u, long long c) {
            if(D[u] > c) {
                D[u] = c;
                q.push({c,u});
            }
        };
        push(u,0);
        while(q.size() and q.top().first < res) {
            auto [c,u] = q.top(); q.pop();
            res = min(res, c + C[u]);
            for(auto& [v,w] : adj[u]) {
                push(v,c+w);
            }
        }
        return res;
    }
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        adj = vector<vector<pair<long long, long long>>>(n);
        for(auto& r : roads) {
            long long u = r[0] - 1, v = r[1] - 1, w = r[2];
            adj[u].push_back({v,w * (1 + k)});
            adj[v].push_back({u,w * (1 + k)});
        }
        vector<long long> res;
        for(int i = 0; i < n; i++) {
            res.push_back(helper(appleCost,i));
        }
        return res;
    }
};