class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        long long n = conversions.size() + 1, mod = 1e9 + 7;
        vector<vector<pair<long long,long long>>> adj(n);
        for(auto& c : conversions) {
            adj[c[0]].push_back({c[1], c[2]});
        }
        vector<int> res(n,1);
        queue<int> q; q.push(0);
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto& [v,w] : adj[u]) {
                q.push(v);
                res[v] = w * res[u] % mod;
            }
        }
        return res;
    }
};