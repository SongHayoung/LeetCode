class Solution {
    vector<vector<pair<int,int>>> adj;
    unordered_map<int,vector<int>> deps;
    vector<int> sums;
    void dfs(int u, int par, int dep, int hi, vector<int>& res, vector<int>& A, int sum) {
        if(deps[A[u]].size()) {
            while(hi <= deps[A[u]].back()) sum -= sums[hi++];
        }
        deps[A[u]].push_back(dep);
        res = min(res, {-sum,dep - hi + 1});
        for(auto& [v,w] : adj[u]) {
            if(v == par) continue;
            sums.push_back(w);
            dfs(v,u,dep+1,hi,res,A,sum + w);
            sums.pop_back();
        }
        deps[A[u]].pop_back();
    }
public:
    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        adj = vector<vector<pair<int,int>>>(edges.size() + 1);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        vector<int> res{0,1};
        dfs(0,-1,0,0,res,nums,0);
        res[0] = -res[0];
        return res;
    }
};