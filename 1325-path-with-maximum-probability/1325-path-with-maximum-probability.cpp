class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double, int>> pq;
        vector<vector<pair<int, double>>> g(n);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back({edges[i][1], succProb[i]});
            g[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        
        vector<double> vis(n, 0.0);
        vis[start] = 1.0;
        pq.push({1.0, start});
        
        while(!pq.empty()) {
            auto [prob, node] = pq.top(); pq.pop();
            if(prob != vis[node]) continue;
            for(auto [near, p] : g[node]) {
                if(vis[near] < vis[node] * p) {
                    vis[near] = vis[node] * p;
                    pq.push({vis[near], near});
                }
            }
        }
        
        return vis[end];
    }
};