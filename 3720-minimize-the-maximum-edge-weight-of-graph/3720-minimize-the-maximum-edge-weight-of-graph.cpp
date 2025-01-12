class Solution {
    bool helper(vector<vector<pair<int,int>>>& adj, int x) {
        vector<bool> vis(adj.size());
        queue<int> q;
        int cnt = adj.size();
        auto push = [&](int u) {
            if(!vis[u]) {
                vis[u] = true;
                cnt--;
                q.push(u);
            }
        };
        push(0);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto& [w,v] : adj[u]) {
                if(w > x) break;
                push(v);
            }
        }
        
        return cnt == 0;
    }
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            int v = e[0], u = e[1], w = e[2];
            adj[u].push_back({w,v});
        }
        for(int i = 0; i < n; i++) sort(begin(adj[i]), end(adj[i]));
        long long l = 0, r = INT_MAX - 1, res = INT_MAX;
        while(l <= r) {
            int m = l + (r - l) / 2;
            bool ok = helper(adj,m);
            if(ok) {
                res = m;
                r = m - 1;
            } else l = m + 1;
        }
        return res == INT_MAX ? -1 : res;
    }
};