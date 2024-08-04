
class Solution {
    int helper(vector<vector<int>>& adj) {
        queue<int> q;
        vector<int> vis(adj.size());
        auto push = [&](int u) {
            if(!vis[u]) {
                vis[u] = true;
                q.push(u);
            }
        };
        int res = 0;
        push(0);
        while(!vis.back()) {
            int qsz = q.size();
            while(qsz--) {
                auto u = q.front(); q.pop();
                for(auto& v : adj[u]) push(v);
            }
            res++;
        }
        return res;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> cost(n, vector<int>(n,n*n));
        for(int i = 0; i < n; i++) {
            cost[i][i] = 0;
            if(i + 1 < n) cost[i][i+1] = 1;
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
                }
            }
        }
        vector<int> res;
        for(auto& q : queries) {
            int u = q[0], v = q[1];
            cost[u][v] = min(cost[u][v], 1);
            cost[0][v] = min(cost[0][v], cost[0][u] + 1);
            cost[u][n-1] = min(cost[u][n-1], cost[u][v] + cost[v][n-1]);
            cost[0][n-1] = min(cost[0][n-1], cost[0][u] + cost[u][v] + cost[v][n-1]);
            
            res.push_back(cost[0][n-1]);
        }
        return res;
    }
};