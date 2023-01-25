class Solution {
    void dfs(int u, int d, vector<long long>& dis, vector<int>& adj) {
        if(dis[u] < d) return;
        dis[u] = d;
        if(adj[u] != -1)
            dfs(adj[u], d + 1, dis, adj);
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<long long> dis1(n, 1ll * INT_MAX * 10), dis2(n, 1ll * INT_MAX * 10);
        dfs(node1, 0, dis1, edges);
        dfs(node2, 0, dis2, edges);

        long long distance = INT_MAX, res = -1;
        for(int i = 0; i < n; i++) {
            if(max(dis1[i],dis2[i]) < distance) {
                distance = max(dis1[i],dis2[i]);
                res = i;
            }
        }

        return res;
    }
};