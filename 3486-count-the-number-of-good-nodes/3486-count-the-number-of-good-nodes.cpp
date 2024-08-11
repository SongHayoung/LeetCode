class Solution {
    int dfs(vector<vector<int>>& adj, int u, int par, int& res) {
        unordered_set<int> us;
        int sum = 1;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            int sub = dfs(adj,v,u,res);
            us.insert(sub);
            sum += sub;
        }
        res += (us.size() <= 1);
        return sum;
    }
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        vector<vector<int>> adj(edges.size() + 1);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        dfs(adj,0,-1,res);
        return res;
    }
};