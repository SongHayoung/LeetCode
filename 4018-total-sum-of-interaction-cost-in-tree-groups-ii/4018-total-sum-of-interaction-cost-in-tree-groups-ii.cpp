const int MAX_N = 101010;
vector<pair<int,int>> adj[MAX_N];
long long level[MAX_N], LCA[MAX_N][22], dep[MAX_N];
void dfs0(long long u, long long lvl, long long par) {
    level[u] = lvl;
    LCA[u][0] = par;
    for(int i = 1; i < 22; i++) {
        LCA[u][i] = LCA[LCA[u][i-1]][i-1];
    }
    for(auto& [v,w] : adj[u]) {
        if(v == par) continue;
        dep[v] = dep[u] + w;
        dfs0(v, lvl + 1, u);
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
long long distance(long long u, long long v) {
    long long lca = lcaQuery(u,v);
    return dep[u] + dep[v] - 2 * dep[lca];
}
class Solution {
    unordered_set<int> blacklist;

    unordered_map<int,pair<long long, long long>> dfs(int u, int par, vector<int>& G, long long& res) {
        unordered_map<int,pair<long long, long long>> mp;
        if(!blacklist.count(G[u-1])) mp[G[u-1]] = {1,0};

        for(auto& [v,w] : adj[u]) {
            if(v == par) continue;
            auto sub = dfs(v,u,G,res);
            

if(mp.size() < sub.size()) swap(mp,sub);
            for(auto& [g,p] : sub) {
                if(!mp.count(g)) mp[g] = p;
                else {
                    auto pp = mp[g];
                    res += p.first * pp.second + pp.first * p.second;
                    mp[g].first += p.first;
                    mp[g].second += p.second;
                }
            }
        }
        for(auto& [_,p] : mp) p.second += p.first;
        return mp;
    }
public:
    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        blacklist = {};
        for(int i = 0; i < n + 1; i++) adj[i].clear();
        unordered_map<int,vector<int>> freq;
        for(int i = 0; i < n; i++) freq[group[i]].push_back(i + 1);
        memset(LCA,0,sizeof LCA);
        long long res = 0;

        for(auto& e : edges) {
            int u = e[0] + 1, v = e[1] + 1;
            adj[u].push_back({v,1});
            adj[v].push_back({u,1});
        }
        dfs0(1,0,0);
        for(auto& [k,vec] : freq) {
            if(vec.size() > 10) continue;
            blacklist.insert(k);
            for(int i = 0; i < vec.size(); i++) {
                for(int j = i + 1; j < vec.size(); j++) {
                    res += distance(vec[i], vec[j]);
                }
            }
        }



        dfs(1,0,group,res);
        return res;
    }
};