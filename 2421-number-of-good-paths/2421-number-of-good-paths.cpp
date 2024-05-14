class Solution {
    int uf[30303];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu, pv);
    }
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        for(int i = 0; i < vals.size(); i++) uf[i] = i;
        int n = vals.size();
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int,vector<int>> mp;
        for(int i = 0; i < n; i++) mp[vals[i]].push_back(i);
        int res = 0;
        for(auto& [_,vec] : mp) {
            for(auto& u : vec) {
                for(auto& v : adj[u]) {
                    if(vals[v] <= vals[u]) uni(u,v);
                }
            }
            unordered_map<int,int> freq;
            for(auto& u : vec) {
                int pu = find(u);
                res += ++freq[pu];
            }
        }
        return res;
    }
};