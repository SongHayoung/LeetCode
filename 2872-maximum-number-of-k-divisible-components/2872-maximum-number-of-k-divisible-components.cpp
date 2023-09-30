class Solution {
    vector<vector<int>> adj;
    int dfs(int u, int par, vector<int>& A, int k, int& res) {
        int sum = A[u];
        for(auto& v : adj[u]) {
            if(v == par) continue;
            sum = (sum + dfs(v,u,A,k,res)) % k;
        }
        sum %= k;
        if(sum == 0) res += 1;
        return sum;
    }
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj = vector<vector<int>>(n);
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        dfs(0,-1,values,k,res);
        return res;
    }
};