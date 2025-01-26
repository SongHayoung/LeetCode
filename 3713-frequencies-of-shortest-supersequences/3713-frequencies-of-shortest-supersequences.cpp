class Solution {
    bool bit(int bit, int x) {
        return (bit>>x) & 1;
    }
    bool ok(int dup, int need, vector<pair<int,int>>& E, int n) {
        vector<vector<int>> adj(n);
        vector<int> deg(n);
        for(auto& [u,v] : E) {
            if(bit(dup,u) or bit(dup,v)) continue;
            adj[u].push_back(v);
            deg[v]++;
        }
        queue<int> q;
        int ok = n;
        for(int i = 0; i < n; i++) if(!deg[i]) q.push(i), ok--;
        while(q.size()) {
            auto u = q.front(); q.pop();
            for(auto& v : adj[u]) {
                if(--deg[v] == 0) q.push(v), ok--;
            }
        }
        return ok == 0;
    }

public:
    vector<vector<int>> supersequences(vector<string>& words) {
        unordered_map<int,int> ord, rord;
        {
            int o = 0, bits = 0;
            auto udt = [&](int b) {
                if(!bit(bits,b)) {
                    ord[b] = o, rord[o] = b;
                    o++;
                    bits |= 1<<b;
                }
            };
            for(auto& w : words) {
                udt(w[0] - 'a'), udt(w[1] - 'a');
            }
        }
        vector<pair<int,int>> edges;
        unordered_map<int,int> skips;
        int skip = 0, must = 0;
        for(auto& w : words) {
            int u = ord[w[0]-'a'], v = ord[w[1]-'a'];
            skips[u] |= 1, skips[v] |= 2;
            if(u == v) must |= 1<<u;
            edges.push_back({u,v});
        }
        for(auto& [k,v] : skips) if(v != 3) skip |= 1<<k;
        int n = ord.size(), mask = (1<<n) - 1;
        vector<vector<int>> dups(n + 1), res;
        for(int dup = 0; dup <= mask; dup++) {
            int need = mask ^ dup;
            if(need & must or dup & skip) continue;
            dups[__builtin_popcount(dup)].push_back(dup);
        }
        for(int i = 0; i <= n; i++) {
            for(auto& dup : dups[i]) {
                int need = mask ^ dup;
                if(ok(dup,need,edges,n)) {
                    vector<int> now(26);
                    for(int i = 0; i < n; i++) now[rord[i]] = bit(dup,i) + 1;
                    res.push_back(now);
                }
            }
            if(res.size()) return res;
        }
        return res;
    }
};