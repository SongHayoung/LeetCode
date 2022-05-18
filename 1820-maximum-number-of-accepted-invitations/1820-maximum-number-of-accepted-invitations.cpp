class Solution {
    vector<int> seen, match;
    bool dfs(int u, int r, vector<vector<int>>& adj) {
        seen[u] = r;
        for(auto v : adj[u]) {
            if(match[v] == 0 or (seen[match[v]] != r and dfs(match[v], r, adj))) {
                match[v] = u;
                return true;
            }
        }
        return false;
    }
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        int res = 0, n = grid.size(), m = grid[0].size();
        vector<vector<int>> adj(n + 1);
        seen = vector<int>(n + 1);
        match = vector<int>(m + 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    adj[i + 1].push_back(j + 1);
                }
            }
        }
        for(int i = 1; i <= n; i++)
            res += dfs(i, i, adj);
        
        return res;
    }
};