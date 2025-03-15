
class Solution {
    unordered_map<int,vector<int>> at;

    void dfs(vector<vector<pair<int,int>>>& adj, vector<int>& A, set<int>& st, vector<int>& C, vector<int>& res, int u, int dep, int par) {
        if(at[C[u]].size()) {
            st.insert(at[C[u]].back());
        }
        A.push_back(dep);
        at[C[u]].push_back(A.size());
        vector<int> now;
        int best = st.size() >= 2 ? *prev(prev(st.end())) : -1;
        if(best == -1) now = {dep, (int)-A.size()};
        else {
            now = {dep - A[best], best - (int)A.size()};
        }
        res = max(res, now);

        for(auto& [v,w] : adj[u]) {
            if(v == par) continue;
            dfs(adj,A,st,C,res,v,dep + w,u);
        }

        A.pop_back();
        at[C[u]].pop_back();
        if(at[C[u]].size()) {
            st.erase(at[C[u]].back());
        }
    }
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = edges.size() + 1;
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        at = {};
        vector<int> res{-1,-1};
        vector<int> A;
        set<int> st;
        dfs(adj,A,st,nums,res,0,0,-1);
        res[1] = -res[1];
        return res;
    }
};