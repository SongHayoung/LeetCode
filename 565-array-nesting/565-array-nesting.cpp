class Solution {
    vector<vector<int>> adj, radj;
    vector<int> vis1, vis2, st, rep;
    vector<int> dp;
    void dfs(int u) {
        vis1[u] = true;
        for(auto& v : adj[u])
            if(!vis1[v])
                dfs(v);
        st.push_back(u);
    }
    void dfs2(int u, int root) {
        vis2[u] = true;
        rep[u] = root;
        for(auto& v : radj[u]) 
            if(!vis2[v])
                dfs2(v,root);
    }
    int dfs3(int u) {
        if(dp[u]) return dp[u];
        dp[u] = 1;
        for(auto& v : adj[u])
            dp[u] = max(dp[u], 1 + dfs3(rep[v]));
        return dp[u];
    }
public:
    int arrayNesting(vector<int>& A) {
        int n = A.size();
        adj = radj = vector<vector<int>>(n);
        vis1 = vis2 = rep = dp = vector<int>(n);
        for(int i = 0; i < n; i++) {
            if(i != A[i]) {
                adj[i].push_back(A[i]);
                radj[A[i]].push_back(i);
            }
        }
        for(int i = 0; i < n; i++) {
            if(!vis1[i]) dfs(i);
        }
        while(!st.empty()) {
            auto u = st.back(); st.pop_back();
            if(vis2[u]) continue;
            dfs2(u,u);
        }
        unordered_map<int, int> freq;
        for(int i = 0; i < n; i++) {
            freq[rep[i]]++;
        }
        int res = 0;
        for(auto& [r, c] : freq) {
            res = max(res, c);
            if(c > 1) dp[r] = c;
        }
        for(int i = 0; i < n; i++) {
            res = max(res, dfs3(rep[i]));
        }
        return res;
    }
};