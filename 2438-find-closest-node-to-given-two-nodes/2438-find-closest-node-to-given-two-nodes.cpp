class Solution {
    void bfs(vector<int>& adj, vector<int>& vis, int u) {
        queue<int> q;
        auto push = [&](int u, int c) {
            if(vis[u] == INT_MAX) {
                vis[u] = c;
                q.push(u);
            }
        };
        push(u,0);
        while(q.size()) {
            auto u = q.front(); q.pop();
            if(adj[u] != -1) push(adj[u], vis[u] + 1);
        }
    }
public:
    int closestMeetingNode(vector<int>& E, int node1, int node2) {
        vector<int> vis1(E.size() + 1, INT_MAX), vis2(E.size() + 1, INT_MAX);
        bfs(E,vis1,node1);
        bfs(E,vis2,node2);
        int res = E.size();
        for(int i = 0; i < E.size(); i++) {
            int ma = max(vis1[i], vis2[i]);
            if(ma < max(vis1[res], vis2[res])) res = i;
        }
        return res == E.size() ? -1 : res;
    }
};