class Solution {
    vector<int> vis, mi;
    vector<vector<int>> st;
    vector<vector<vector<int>>> bccs;
    int id = 1;
    void dfs(int u, int par, vector<vector<int>>& adj) {
        vis[u] = mi[u] = id++;
        for(auto& v : adj[u]) {
            if(par == v) continue;
            if(vis[u] > vis[v]) {
                st.push_back({u,v});
            }
            
            if(vis[v]) {
                mi[u] = min(mi[u], vis[v]);
            } else {
                dfs(v, u, adj);
                mi[u] = min(mi[u], mi[v]);
                if(vis[u] <= mi[v]) {
                    bccs.emplace_back();
                    while(!st.empty()) {
                        auto e = st.back(); st.pop_back();
                        bccs.back().push_back(e);
                        if(e[0] == u and e[1] == v) break;
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }
        vis = vector<int>(n);
        mi = vector<int>(n);
        bccs.clear();
        st.clear();
        id = 1;
        dfs(0, -1, adj);
        vector<vector<int>> res;
        for(auto& bcc : bccs) {
            if(bcc.size() == 1)
                res.push_back(bcc[0]);
        }
        return res;
    }
};