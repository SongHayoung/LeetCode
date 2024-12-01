class Solution {
    void dfs(vector<vector<int>>& adj, int u, int par, int k, int& cnt) {
        cnt++;
        if(!k) return;
        for(auto& v : adj[u]) {
            if(v != par) dfs(adj,v,u,k-1,cnt);
        }
    }
    vector<int> helper(vector<vector<int>>& E, int k) {
        if(k == -1) return vector<int>(E.size() + 1);
        vector<int> res(E.size() + 1);
        vector<vector<int>> adj(E.size() + 1);
        for(auto& e : E) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0; i < res.size(); i++) {
            dfs(adj,i,-1,k,res[i]);
        }
        return res;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<int> cost1 = helper(edges1, k), cost2 = helper(edges2, k - 1);
        int ma = *max_element(begin(cost2), end(cost2));
        for(auto& c : cost1) c += ma;
        return cost1;
    }
};