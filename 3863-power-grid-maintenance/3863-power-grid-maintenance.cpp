int vis[101010];
bool online[101010];
class Solution {
    vector<vector<int>> adj;
    void dfs(int u, int root) {
        vis[u] = root;
        for(auto& v : adj[u]) {
            if(!vis[v]) dfs(v,root);
        }
    }
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        memset(vis, 0, sizeof vis);
        adj = vector<vector<int>>(c + 1);
        for(auto& c : connections) {
            int u = c[0], v = c[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= c; i++) if(!vis[i]) dfs(i,i);
        unordered_map<int,deque<int>> groups;
        for(int i = 1; i <= c; i++) {
            groups[vis[i]].push_back(i);
            online[i] = 1;
        }
        vector<int> res;
        for(auto& q : queries) {
            int op = q[0], u = q[1];
            if(op == 1) {
                if(online[u]) res.push_back(u);
                else {
                    int g = vis[u];
                    while(groups[g].size() and !online[groups[g][0]]) groups[g].pop_front();
                    res.push_back(groups[g].size() ? groups[g][0] : -1);
                }
            }
            if(op == 2) online[u] = 0;
        }
        return res;
    }
};