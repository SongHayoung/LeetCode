class Solution {
    vector<vector<int>> adj;
    int dfs(int u, int p, vector<bool>& A) {
        int res = 0;

        for(auto& v : adj[u])
            if(v != p)
                res += dfs(v, u, A);
        return res + (res or A[u] ? 2 : 0);
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj = vector<vector<int>>(n);
        for(auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return max(0, dfs(0, -1, hasApple) - 2);
    }
};
