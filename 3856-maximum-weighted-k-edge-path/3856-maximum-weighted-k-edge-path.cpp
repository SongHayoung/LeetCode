class Solution {
    vector<pair<int,int>> adj[505];
    int ind[505];
public:
    int maxWeight(int n, vector<vector<int>>& edges, int K, int T) {
        if(!K) return 0;
        for(int i = 0; i < n; i++) adj[i].clear();
        memset(ind,0,sizeof ind);
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            ind[v]++;
            adj[u].push_back({v,w});
        }
        queue<int> q;
        vector<unordered_map<int,unordered_set<int>>> A(n);
        auto push = [&](int u) {
            q.push(u);
            A[u][0].insert(0);
        };
        for(int i = 0; i < n; i++) if(!ind[i]) push(i);
        int res = -1;
        while(q.size()) {
            int u = q.front(); q.pop();
            for(auto& [v,w] : adj[u]) {
                if(--ind[v] == 0) push(v);
                for(auto& [dep, vals] : A[u]) {
                    for(auto& val : vals) {
                        int nval = val + w;
                        if(nval >= T) continue;
                        if(dep + 1 == K) res = max(res, nval);
                        else {
                            A[v][dep + 1].insert(nval);
                        }
                    }
                }
            }
        }
        return res;
    }
};