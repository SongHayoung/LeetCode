long long mod = 1e9 + 7;
long long modpow(long long n, long long x, long long MOD = mod) {if(x<0){return modpow(modpow(n,-x,MOD),MOD-2,MOD);}n%=MOD;long long res=1;while(x){if(x&1){res=res*n%MOD;}n=n*n%MOD;x>>=1;}return res;}
class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        if(n == 1) return 0;
        vector<int> dep(n);
        vector<vector<int>> adj(n);
        for(auto& e : edges) {
            int u = e[0] - 1, v = e[1] - 1;
            adj[u].push_back(v);
        }
        queue<int> q;
        q.push(0);
        int d = 0;
        while(q.size()) {
            auto u = q.front(); q.pop();
            for(auto& v : adj[u]) {
                d = dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
        return modpow(2,d-1);
    }
};