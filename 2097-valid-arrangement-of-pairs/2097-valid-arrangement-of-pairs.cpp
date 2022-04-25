#define ll long long
#define um unordered_map
#define vll vector<ll>
class Solution {
    um<ll,ll> in, out;
    um<ll,vll> adj;
    vector<vector<int>> res;
    void dfs(ll u) {
        while(!adj[u].empty()) {
            auto v = adj[u].back(); adj[u].pop_back();
            dfs(v);
            res.push_back({(int)v,(int)u});
        }
    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& p) {
        ll u = p[0][0], n = p.size();
        for(ll i = 0; i < n; i++) {
            in[p[i][0]]++;
            out[p[i][1]]++;
            adj[p[i][1]].push_back(p[i][0]);
        }
        
        for(auto& [uu, _] : adj)
            if(out[uu] - in[uu] == 1) u = uu;
        dfs(u);
      //  reverse(begin(res),end(res));
        return res;
    }
};