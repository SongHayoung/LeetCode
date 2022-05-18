class Solution {
    vector<vector<int>> flo, cap;
    vector<int> path;
    vector<vector<int>> adj;
    int source, sink;
    
    bool bfs(int u, int v) {
        path = vector<int>(sink + 1);
        queue<int> q;
        q.push(u);
        while(!q.empty() and !path[v]) {
            auto n = q.front(); q.pop();
            for(auto& m : adj[n]) {
                if(cap[n][m] - flo[n][m] > 0 and !path[m]) {
                    path[m] = n;
                    q.push(m);
                }
            }
        }
        
        return path[v] != 0;
    }
    
    int mcmf() {
        int res = 0;
        while(bfs(source, sink)) {
            int v = sink, mi = INT_MAX;
            while(v != source) {
                int u = path[v];
                mi = min(mi, cap[u][v] - flo[u][v]);
                v = u;
            }
            v = sink;
            while(v != source) {
                int u = path[v];
                flo[u][v] += mi;
                flo[v][u] -= mi;
                v = u;
            }
            res++;
        }
        return res;
    }
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        source = n + m + 10, sink = n + m + 11;
        path = vector<int>(sink + 1);
        flo = cap = vector<vector<int>>(sink + 1, vector<int>(sink + 1));
        adj = vector<vector<int>>(sink + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!grid[i][j]) continue;
                adj[i+1].push_back(n + j+1);
                adj[n + j+1].push_back(i+1);
                
                cap[i+1][n + j + 1] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            cap[source][i + 1] = 1;
            adj[source].push_back(i + 1);
            adj[i + 1].push_back(source);
        }
        for(int i = 0; i < m; i++) {
            cap[n + i + 1][sink] = 1;
            adj[sink].push_back(n + i+1);
            adj[n + i+1].push_back(sink);
        }
        
        return mcmf();
    }
};