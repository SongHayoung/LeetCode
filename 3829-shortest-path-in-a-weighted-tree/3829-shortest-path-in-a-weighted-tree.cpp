class Solution {
    vector<int> dep;
    int id;
    vector<vector<pair<int,int>>> adj;
    vector<int> costs;
    vector<int> in, out;
    void dfs(int u, int par, int c, int d) {
        in[u] = id++;
        costs.push_back(c);
        dep[u] = d;
        for(auto& [v,w] : adj[u]) {
            if(v == par) continue;
            dfs(v,u,w, d + 1);
        }
        out[u] = id++;
        costs.push_back(-c);
    }
    vector<int> fenwick;
    void update(int n, int w) {
        while(n < fenwick.size()) {
            fenwick[n] += w;
            n += n & -n;
        }
    }
    int query(int n) {
        int res = 0;
        while(n) {
            res += fenwick[n];
            n -= n & -n;
        }
        return res;
    }
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        id = 1, adj = vector<vector<pair<int,int>>>(n), costs = {0}, in = out = dep = vector<int>(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            u -= 1, v -= 1;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs(0,-1,0,0);
        fenwick = vector<int>(id + 1);
        for(int i = 1; i < costs.size(); i++) update(i,costs[i]);
        vector<int> res;
        for(auto& q : queries) {
            int op = q[0];
            if(op == 1) {
                int u = q[1] - 1, v = q[2] - 1, w = q[3], ch = dep[u] > dep[v] ? u : v;
                int e1 = in[ch], e2 = out[ch];
                update(e1, -costs[e1]);
                update(e2, -costs[e2]);
                costs[e1] = w, costs[e2] = -w;
                update(e1, costs[e1]);
                update(e2, costs[e2]);
            } else res.push_back(query(in[q[1] - 1]));
        }

        return res;
    }
};
