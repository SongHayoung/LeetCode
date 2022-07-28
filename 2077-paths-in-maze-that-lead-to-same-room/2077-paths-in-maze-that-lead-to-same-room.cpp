class Solution {
    vector<vector<int>> adj;
    vector<unordered_set<int>> radj;
    int dfs(int root, int u, int d, int par) {
        if(d == 2) return radj[u].count(root);
        int res = 0;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            res += dfs(root, v, d + 1, u);
        }
        return res;
    }
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        adj = vector<vector<int>>(n+1);
        radj = vector<unordered_set<int>>(n + 1);
        for(auto c : corridors) {
            int u = c[0], v = c[1];
            adj[min(u,v)].push_back(max(u,v));
            radj[max(u,v)].insert(min(u,v));
        }
        
        long long res = 0;
        
        for(int i = 1; i <= n; i++) res += dfs(i,i,0,-1);
        
        return res;
    }
};