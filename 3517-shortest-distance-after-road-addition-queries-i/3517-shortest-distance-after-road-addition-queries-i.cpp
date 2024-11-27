
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
        vector<vector<int>> adj(n);
        for(int i = 0; i < n - 1; i++) {
            adj[i].push_back(i+1);
        }
        vector<int> res;
        for(auto& q : queries) {
            adj[q[0]].push_back(q[1]);
            res.push_back(helper(adj));
        }
        return res;
    }
};