class Solution {
    vector<vector<int>> adj;
    vector<int> sub;
    int dfs(int u) {
        int& res = sub[u] = 1;
        for(auto& v : adj[u]) {
            res += dfs(v);
        }
        return res;
    }
    long long query(int u, int n) {
        long long res = 1, rem = n - 1;
        for(auto& v : adj[u]) {
            res *= sub[v];
            rem -= sub[v];
        }
        if(rem) res *= rem;
        return res;
    }
public:
    int countHighestScoreNodes(vector<int>& par) {
        adj = vector<vector<int>>(par.size());
        sub = vector<int>(par.size());
        for(int i = 0; i < par.size(); i++) {
            if(par[i] == -1) continue;
            adj[par[i]].push_back(i);
        }
        dfs(0);
        long long ma = -1, cnt = 0;
        for(int i = 0; i < par.size(); i++) {
            long long now = query(i,par.size());
            if(ma == now) cnt++;
            else if(ma < now) {
                ma = now;
                cnt = 1;
            }
        }
        
        return cnt;
    }
};