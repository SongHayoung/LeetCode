
class Solution {
    long long dfs(vector<vector<int>>& adj, int u, long long h) {
        long long res = h;
        for(auto& v : adj[u]) {
            res = max(res,dfs(adj,v,h+1));
        }
        return res;
    }
    long long dfs1(vector<vector<int>>& adj, int u, int d, int h, vector<int>& A) {
        long long res = 1ll * (h - d + 1) * A[u];
        for(auto& v : adj[u]) {
            res += dfs1(adj,v,d+1,h,A);
        }
        return res;
    }
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for(int i = 1; i < n; i++) adj[parent[i]].push_back(i);
        long long h = dfs(adj,0,0);
        return dfs1(adj,0,0,h,nums);
    }
};