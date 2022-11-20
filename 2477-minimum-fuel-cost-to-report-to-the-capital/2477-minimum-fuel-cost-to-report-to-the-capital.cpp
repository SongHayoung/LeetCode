class Solution {
    int dfs(int u, int par, vector<vector<int>>& adj, int dep, long long & res, int& s) {
        int now = 1;
        for(auto v : adj[u]) {
            if(v == par) continue;
            now += dfs(v,u,adj,dep + 1, res,s);
            if(now >= s) {
                res += dep;
                now -= s;
            }
        }
        if(now > 0 and u != 0) res += 1;
        return now;
    }
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long res = 0, n = roads.size() +1;
        vector<vector<int>> adj(n);
        for(auto r : roads) {
            int u = r[0], v = r[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,adj,0,res, seats);
        return res;
    }
};