class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src == dst) return 0;
        vector<int> vis(n, INT_MAX);
        vector<vector<pair<int,int>>> g(n);
        for(auto f : flights) {
            g[f[0]].push_back({f[1],f[2]});
        }
        queue<int> q;
        q.push(src);
        vis[src] = 0;
        k += 1;
        while(k--) {
            int sz = q.size();
            unordered_set<int> cvis;
            vector<int> cost = vis;
            while(sz--) {
                auto node = q.front(); q.pop();
                for(auto [near, price] : g[node]) {
                    if(vis[near] > cost[node] + price) {
                        vis[near] = cost[node] + price;
                        cvis.insert(near);
                    }
                }
            }
            for(auto nxt : cvis)
                q.push(nxt);
        }
        
        
        return vis[dst] == INT_MAX ? -1 : vis[dst];
    }
};