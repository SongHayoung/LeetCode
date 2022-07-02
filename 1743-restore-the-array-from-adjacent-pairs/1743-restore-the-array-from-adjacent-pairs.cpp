class Solution {
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<int>& res, int par = INT_MIN) {
        res.push_back(u);
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs(adj, v, res, u);
        }
    }
public:
    vector<int> restoreArray(vector<vector<int>>& A) {
        unordered_map<int, vector<int>> adj;
        for(auto& a : A) {
            int u = a[0], v = a[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res;
        
        for(auto& [u, vs] : adj) {
            if(vs.size() == 1) {
                dfs(adj, u, res);
                return res;
            }
        }
        
        return res;
    }
};