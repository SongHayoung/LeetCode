const int MAX_N = 121;
int source = MAX_N - 2, sink = MAX_N - 1;
int cost[MAX_N][MAX_N], flo[MAX_N][MAX_N], cap[MAX_N][MAX_N], path[MAX_N];
vector<int> adj[MAX_N];

void connect(int u, int v, int capacity, int weight) {
    adj[u].push_back(v);
    adj[v].push_back(u);

    cap[u][v] += capacity;

    cost[u][v] += weight;
    cost[v][u] -= weight;
}

bool bfs(int u, int v) {
    vector<int> w(MAX_N, 2020);
    bool inc[MAX_N];
    memset(path, 0, sizeof path);
    memset(inc, 0, sizeof inc);
    queue<int> q;
    q.push(u);
    w[u] = 0;

    while(q.size()) {
        auto n = q.front(); q.pop();
        inc[n] = false;
        for(auto& m : adj[n]) {
            if(cap[n][m] - flo[n][m] > 0 and w[n] + cost[n][m] < w[m]) {
                w[m] = w[n] + cost[n][m];
                path[m] = n;
                if(!inc[m]) {
                    inc[m] = true;
                    q.push(m);
                }
            }
        }
    }
    return path[v] != 0;
}
class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        memset(cap, 0, sizeof cap);
        memset(flo, 0, sizeof flo);
        memset(cost, 0, sizeof cost);
        for(int i = 0; i < MAX_N; i++) adj[i].clear();
        
        int n = grid.size(), m = grid[0].size();
        for(int i = 0; i < n; i++) {
            connect(source, i + 101, 1, 0);
            unordered_set<int> vis;
            for(int j = 0; j < m; j++) {
                if(vis.count(grid[i][j])) continue;
                vis.insert(grid[i][j]);
                connect(i + 101, grid[i][j], 1, 0);
            }
        }
        for(int j = 1; j <= 100; j++) {
            connect(j, sink, 1, -j);
        }
        int res = 0, flow = 0;
        while(bfs(source, sink)) {
            int v = sink, mi = 2020;
            while(source != v) {
                int u = path[v];
                mi = min(mi, cap[u][v] - flo[u][v]);
                v = u;
            }
            v = sink;
            flow += mi;
            while(source != v) {
                int u = path[v];
                res += mi * cost[u][v];
                flo[u][v] += mi;
                flo[v][u] -= mi;
                v = u;
            }
        }
        return -res;
    }
};