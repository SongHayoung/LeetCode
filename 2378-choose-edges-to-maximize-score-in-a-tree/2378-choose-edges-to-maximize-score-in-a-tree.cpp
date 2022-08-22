class Solution {
    vector<vector<pair<long long, long long>>> adj;
    pair<long long, long long> dfs(int u) {
        long long inc = 0, exc = 0;
        for(auto& [v,w] : adj[u]) {
            auto [vinc, vexc] = dfs(v);
            inc = max(inc, w + vexc - vinc);
            exc += vinc;
        }
        return {inc + exc, exc};
    }
public:
    long long maxScore(vector<vector<int>>& A) {
        int n = A.size();
        adj = vector<vector<pair<long long, long long>>>(n);
        for(int i = 1; i < n; i++) {
            int par = A[i][0], w = A[i][1];
            adj[par].push_back({i,max(0,w)});
        }
        auto [inc, exc] = dfs(0);
        return max(inc,exc);
    }
};