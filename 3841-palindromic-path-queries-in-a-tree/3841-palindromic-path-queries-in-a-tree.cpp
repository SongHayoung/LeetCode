
struct Seg {
    int mi, ma, val, lazy;
    Seg *le, *ri;
    Seg(int l, int r) : mi(l), ma(r), val(0), lazy(0), le(nullptr), ri(nullptr) {
        if(l^r) {
            int m = l + (r - l) / 2;
            le = new Seg(l,m);
            ri = new Seg(m+1,r);
        }
    }
    void propagate() {
        if(lazy) {
            val ^= lazy;
            if(le) le->lazy ^= lazy;
            if(ri) ri->lazy ^= lazy;
            lazy = 0;
        }
    }
    void update(int l, int r, int v) {
        propagate();
        if(l <= mi and ma <= r) {
            lazy ^= v;
            propagate();
            return;
        }
        if(l > ma or r < mi) return;
        le->update(l,r,v);
        ri->update(l,r,v);
    }
    int query(int x) {
        propagate();
        if(mi <= x and x <= ma) {
            if(mi == x and x == ma) return val;
            return le->query(x) ^ ri->query(x);
        }
        return 0;
    }
};
const int MAX_N = 101010;
vector<pair<int,int>> adj[MAX_N];
long long level[MAX_N], LCA[MAX_N][22], dep[MAX_N];
void dfs(long long u, long long lvl, long long par) {
    level[u] = lvl;
    LCA[u][0] = par;
    for(int i = 1; i < 22; i++) {
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
    }
    for(auto& [v,w] : adj[u]) {
        if(v == par) continue;
        dep[v] = dep[u] + w;
        dfs(v, lvl + 1, u);
    }
}
long long lcaQuery(long long u, long long v) {
    if(level[u] < level[v]) swap(u, v);
    long long diff = level[u] - level[v];
    for(long long i = 0; diff; i++, diff /= 2) {
        if(diff & 1) u = LCA[u][i];
    }
    if(u != v) {
        for(int i = 21; i >= 0; i--) {
            if(LCA[u][i] == LCA[v][i]) continue;
            u = LCA[u][i];
            v = LCA[v][i];
        }
        u = LCA[u][0];
    }
    return u;
}
class Solution {
    void dfs0(int u, int par, vector<vector<int>>& adj, int& p, vector<pair<int,int>>& at) {
        at[u].first = p++;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs0(v,u,adj,p,at);
        }
        at[u].second = p++;
    }
public:
     vector<string> parse(string q) {
        vector<string> res;
        string s = "";
        for(auto& ch : q) {
            if(ch == ' ') {
                res.push_back(s); s = "";
            } else s.push_back(ch);
        }
        res.push_back(s);
        return res;
    }
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adjs(n);
        for(int i = 0; i <= n; i++) adj[i].clear();
        memset(LCA,0,sizeof LCA);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adjs[u].push_back(v);
            adjs[v].push_back(u);
            adj[u+1].push_back({v+1,1});
            adj[v+1].push_back({u+1,1});
        }
        vector<pair<int,int>> at(n);
        int p = 0;
        dfs0(0,-1,adjs,p,at);
        dfs(1,0,0);
        Seg* seg = new Seg(0,p);
        for(int i = 0; i < n; i++) {
            seg->update(at[i].first, at[i].second, 1<<(s[i] - 'a'));
        }
        vector<bool> res;
        for(auto& q: queries) {
            auto vq = parse(q);
            if(vq[0] == "query") {
                int u =stoi(vq[1]), v = stoi(vq[2]);
                int lca = lcaQuery(u+1,v+1) - 1;
                int op = seg->query(at[u].first) ^ seg->query(at[v].first) ^ (1<<(s[lca]-'a'));
                res.push_back(__builtin_popcount(op) <= 1);
            } else {
                int id = stoi(vq[1]);
                seg->update(at[id].first, at[id].second, (1<<(s[id]-'a')) ^ (1<<(vq[2][0]-'a')));
                s[id] = vq[2][0];
            }
        }
        return res;
    }
};