class Solution {
    void dfs1(vector<vector<int>>& adj, vector<int>& h, int u, int par) {
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs1(adj,h,v,u);
            h[u] = max(h[u], h[v] + 1);
        }
    }
    void dfs2(vector<vector<int>>& adj, vector<int>& h, int u, int par, int parH) {
        vector<pair<int,int>> best{{parH, par}, {parH, par}};
        h[u] = max(h[u], parH);
        for(auto& v : adj[u]) {
            if(v == par) continue;
            best.push_back({h[v] + 1, v});
            sort(rbegin(best), rend(best));
            best.pop_back();
        }
        auto pick = [&](int v) {
            for(auto& [count, vertex] : best) if(vertex != v) return count;
            return -1;
        };
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs2(adj,h,v,u,pick(v) + 1);
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> h(n);
        dfs1(adj,h,0,-1);
        dfs2(adj,h,0,-1,0);
        int mi = *min_element(begin(h), end(h));
        vector<int> res;
        for(int i = 0; i < n; i++) if(h[i] == mi) res.push_back(i);
        return res;
    }
};