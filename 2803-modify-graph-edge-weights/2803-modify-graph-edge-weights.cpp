class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& E, int s, int d, int t) {
        vector<long long> vis(n,INT_MAX);
        vector<int> e;
        vector<vector<int>> adj(n);
        for(int i = 0; i < E.size(); i++) {
            if(E[i][2] == -1) e.push_back(i), E[i][2] = 2e9;
            {
                int u = E[i][0], v = E[i][1], w = E[i][2];
                adj[u].push_back(i);
                adj[v].push_back(i);
            }
        }
        auto run = [&]() {
            priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<>> q;
            vis = vector<long long>(n, INT_MAX);
            auto push = [&](long long u, long long c) {
                if(vis[u] > c) {
                    vis[u] = c;
                    q.push({c,u});
                }
            };
            push(s,0);
            while(q.size()) {
                auto [c,u] = q.top(); q.pop();
                if(vis[u] != c) continue;
                for(auto& idx : adj[u]) {
                    long long w = E[idx][2], v = E[idx][0] ^ E[idx][1] ^ u;
                    push(v,c+w);
                }
            }
        };
        run();
        if(vis[d] < t) return {};
        if(vis[d] == t) return E;
        for(auto& x : e) {
            E[x][2] = 1;
            run();
            if(vis[d] <= t) {
                E[x][2] += t - vis[d];
                return E;
            }
        }
        return {};
    }
};