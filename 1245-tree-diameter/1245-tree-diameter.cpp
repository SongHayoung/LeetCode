class Solution {
    vector<int> adj[10101];
    int res = 0;
    int dfs(int u, int par) {
        int dis = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            pq.push(dfs(v,u) + 1);
            if(pq.size() > 2) pq.pop();
        }
        if(pq.size() == 2) {
            auto tp = pq.top(); pq.pop();
            res = max(res, tp + pq.top());
            dis = pq.top();
        } else if(pq.size()) {
            res = max(res, pq.top());
            dis = pq.top();
        }
        return dis;
    }
public:
    int treeDiameter(vector<vector<int>>& edges) {
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0, -1);
        return res;
    }
};