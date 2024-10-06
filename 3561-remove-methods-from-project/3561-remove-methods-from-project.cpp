
class Solution {
    int uf[101010];
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& methodsRelationship) {
        iota(begin(uf),end(uf),0);
        vector<vector<int>> adj(n);
        for(auto& e : methodsRelationship) {
            int u = e[0], v = e[1];
            uni(u,v);
            adj[u].push_back(v);
        }
        vector<bool> fl(n);
        queue<int> q;
        q.push(k); fl[k] = true;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto& v : adj[u]) {
                if(fl[v]) continue;
                fl[v] = true;
                q.push(v);
            }
        }
        unordered_map<int, int> gc, flc;
        for(int i = 0; i < n; i++) {
            int r = find(i);
            gc[r]++;
            flc[r] += fl[i];
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            int r = find(i);
            if(gc[r] == flc[r]) continue;
            res.push_back(i);
        }
        return res;
    }
};