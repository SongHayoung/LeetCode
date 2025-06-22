class Solution {
    long long dfs(vector<vector<int>>& adj, vector<long long>& A, int& res, int u, int par) {
        if(adj[u].size() == 1 and adj[u][0] == par) return A[u];
        long long best = 0, cnt = 0;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            A[v] += A[u];
            long long sub = dfs(adj,A,res,v,u);
            if(best == sub) cnt++;
            else if(best < sub) best = sub, cnt = 1;
        }
        res += adj[u].size() - !!u - cnt;
        return best;
    }
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        if(n == 1) return 0;
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int res = 0;
        vector<long long> C;
        for(auto& c : cost) C.push_back(c);
        dfs(adj,C,res,0,-1);
        return res;
    }
};