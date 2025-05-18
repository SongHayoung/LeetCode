vector<pair<int,int>> adj[101010];
int parent[101010], depth[101010], heavy[101010], head[101010], cnt[101010], dist[101010];
int dfs1(int u, int p, int w) {
    parent[u] = p;
    dist[u] = w;
    cnt[u] = 1;
    heavy[u] = -1;
    int best = 0;
    for (auto& [v,c] : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        int sz = dfs1(v, u, w + c);
        if (sz > best) {
            best = sz;
            heavy[u] = v;
        }
        cnt[u] += sz;
    }
    return cnt[u];
}

void dfs2(int u, int h) {
    head[u] = h;
    if (heavy[u] != -1) dfs2(heavy[u], h);
    for (auto& [v,w] : adj[u]) {
        if (v == parent[u] || v == heavy[u]) continue;
        dfs2(v, v);
    }
}

void build(int root = 0) {
    depth[root] = 0;
    dfs1(root, -1, 0);
    dfs2(root, root);
}

int query(int a, int b) {
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]]) a = parent[head[a]];
        else b = parent[head[b]];
    }
    return depth[a] < depth[b] ? a : b;
}

int distance(int u, int v) {
    int lca = query(u,v);
    return dist[u] + dist[v] - 2 * dist[lca];
}
int median(int a, int b, int c) {
    int x = query(a,b), y = query(a,c), z = query(b,c);
    int res = x;
    if(depth[y] > depth[res]) res = y;
    if(depth[z] > depth[res]) res = z;
    return res;
}
int distance(int a, int b, int c) {
    int best = median(a,b,c);
    return distance(best,a) + distance(best,b) + distance(best,c);
}

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        for(int i = 0; i < n; i++) adj[i].clear();
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        dfs1(0,0,0);
        dfs2(0,0);
        vector<int> res;
        for(auto& q : queries) {
            res.push_back(distance(q[0], q[1], q[2]));
        }
        return res;
    }
};
