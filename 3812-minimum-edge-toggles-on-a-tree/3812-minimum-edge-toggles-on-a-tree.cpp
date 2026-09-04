
class Solution {
    int dfs(vector<vector<pair<int,int>>>& adj, int u, int par, vector<int>& res, string& s, string& t) {
        int sub = s[u] != t[u];
        for (auto [v, idx] : adj[u]) {
            if (v == par) continue;
            int child = dfs(adj, v, u, res, s, t);
            if (child) res.push_back(idx);
            sub ^= child;
        }
        return sub;
    }

public:
    vector<int> minimumFlips(int n, vector<vector<int>>& edges, string start, string target) {
        if((count(begin(start),end(start),'0') + count(begin(target),end(target),'0')) & 1) return {-1};
        vector<vector<pair<int,int>>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back({v, i});
            adj[v].push_back({u, i});
        }
        vector<int> res;
        dfs(adj,0, -1,res,start,target);
        sort(res.begin(), res.end());
        return res;
    }
};