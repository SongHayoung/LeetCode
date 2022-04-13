class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        vector<vector<pair<int,int>>> g(n);
        vector<int> vis(n,0);
        
        for(auto e : edges) {
            g[e[0]].push_back({e[1],e[2]});
            g[e[1]].push_back({e[0],e[2]});
        }
        
        priority_queue<pair<int,int>> pq;
        pq.push({maxMoves, 0});
        
        int res = 0;
        while(!pq.empty()) {
            auto [mv, node] = pq.top(); pq.pop();
            if(!vis[node]) {
                vis[node] = mv;
                res++;
                for(auto [near, cost] : g[node]) {
                    int nmv = mv - cost - 1;
                    if(!vis[near] and nmv >= 0) {
                        pq.push({nmv, near});
                    }
                }
            }
        }
        for(auto e : edges) {
            res += min(vis[e[0]] + vis[e[1]], e[2]);
        }
        return res;
    }
};