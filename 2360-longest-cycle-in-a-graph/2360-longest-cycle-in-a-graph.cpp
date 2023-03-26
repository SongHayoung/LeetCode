class Solution {
    vector<vector<int>> adj, radj;
    vector<int> vis1, vis2, st, rep;
    void dfs(int u) {
        vis1[u] = true;
        for(auto& v : adj[u]) {
            if(!vis1[v])
                dfs(v);
        }
        st.push_back(u);
    }
    void dfs2(int u, int root) {
        vis2[u] = true;
        rep[u] = root;
        for(auto& v : radj[u]) {
            if(!vis2[v])
                dfs2(v,root);
        }
    }
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size(), res = -1;
        adj = radj = vector<vector<int>>(n);
        vis1 = vis2 = rep = vector<int>(n);
        for(int i = 0; i < n; i++) {
            if(edges[i] == -1) continue;
            adj[i].push_back(edges[i]);
            radj[edges[i]].push_back(i);
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
        for(auto& [_, c] : freq) {
            if(c == 1) continue;
            res = max(res, c);
        }
        return res;
    }
};