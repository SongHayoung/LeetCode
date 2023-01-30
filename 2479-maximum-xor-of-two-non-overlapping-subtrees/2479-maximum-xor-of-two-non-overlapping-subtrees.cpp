struct Trie {
    Trie* next[2];
    bool eof = false;
    Trie() {
        memset(next, 0, sizeof next);
    }
    void insert(long long v, long long mask = 60) {
        if(mask == -1) eof = true;
        else {
            bool bit = v & (1ll<<mask);
            if(!next[bit]) next[bit] = new Trie();
            next[bit]->insert(v,mask - 1);
        }
    }
    long long query(long long x, long long mask = 60) {
        if(eof) return 0;
        bool bit = x & (1ll<<mask);
        if(!next[!bit]) {
            if(!next[bit]) return 0;
            return next[bit]->query(x,mask-1);
        }
        return (1ll<<mask) | next[!bit]->query(x,mask - 1);
    }
};
class Solution {
    void dfs(vector<vector<int>>& adj, vector<long long>& sub, vector<int>& A, int u, int par) {
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs(adj,sub,A,v,u);
            sub[u] += sub[v];
        }
        sub[u] += A[u];
    }
    void dfs2(vector<vector<int>>& adj, vector<long long>& sub, long long u, long long par, Trie* trie, long long& res) {
        long long x = trie->query(sub[u]);
        res = max(res, x);
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs2(adj,sub,v,u,trie,res);
        }
        trie->insert(sub[u]);
    }
public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> adj(n);
        for(auto e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int root = 0, par = -1;
        if(adj[root].size() == 1) {
            par = root; root = adj[root][0];
            while(adj[root].size() <= 2) {
                for(auto v : adj[root]) {
                    if(v == par) continue;
                    par = root;
                    root = v;
                    break;
                }
                if(adj[root].size() == 1) break;
            }
            if(adj[root].size() == 1) return 0;
        }
        vector<long long> sub(n);
        dfs(adj,sub,values,root,par);
        Trie* trie = new Trie();
        long long res = 0;
        dfs2(adj,sub,root,par,trie,res);
        return res;
    }
};
