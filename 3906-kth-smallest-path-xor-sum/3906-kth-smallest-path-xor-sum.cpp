

struct Fenwick {
    int n;
    vector<int> f;
    Fenwick(int _n): n(_n), f(n+1, 0) {}
    void update(int i, int delta) {
        for (; i <= n; i += i & -i) {
            f[i] += delta;
        }
    }
    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) {
            s += f[i];
        }
        return s;
    }
    int total() {
        return query(n);
    }
    int kth(int k) {
        int idx = 0;
        int bitMask = 1 << (31 - __builtin_clz(n));
        for (; bitMask > 0; bitMask >>= 1) {
            int nxt = idx + bitMask;
            if (nxt <= n && f[nxt] < k) {
                k -= f[nxt];
                idx = nxt;
            }
        }
        return idx + 1;
    }
};

class Solution {
    vector<int> in,out,euler;
    void dfs(vector<vector<int>>& adj, int u, vector<int>& vals) {
        for(auto& v : adj[u]) {
            vals[v] ^= vals[u];
            dfs(adj,v,vals);
        }
    }
    void dfs2(vector<vector<int>>& adj, int u, int& t, vector<int>& vals) {
        in[u] = t;
        euler[t++] = vals[u];
        for(auto& v : adj[u]) dfs2(adj,v,t,vals);
        out[u] = t - 1;
    }
public:
    vector<int> kthSmallest(vector<int>& par, vector<int>& vals, vector<vector<int>>& queries) {
        int n = par.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; i++) {
            adj[par[i]].push_back(i);
        }
        dfs(adj,0,vals);
        in = out = euler = vector<int>(n);
        int t = 0;
        dfs2(adj,0,t,vals);

        vector<int> S = euler;
        sort(begin(S), end(S));
        S.erase(unique(begin(S), end(S)), end(S));

        vector<int> A(n);
        for(int i = 0; i < n; i++) {
            A[i] = lower_bound(begin(S), end(S), euler[i]) - begin(S);
        }
        vector<array<int,4>> Q;
        for(int i = 0; auto& q : queries) {
            int u = q[0], k = q[1];
            Q.push_back({in[u], out[u], k, i++});
        }

        int buc = max(1, (int)sqrt(n));
        sort(begin(Q), end(Q), [&](auto& a, auto& b) {
            int abuc = a[0] / buc, bbuc = b[0] / buc;
            if(abuc != bbuc) return abuc < bbuc;
            return abuc & 1 ? a[1] > b[1] : a[1] < b[1];
        });
        int m = S.size();
        vector<int> freq(m);
        Fenwick fenwick(m);

        auto udt = [&](int idx, int op) {
            idx = A[idx];
            if(op == 1) {
                if(++freq[idx] == 1) fenwick.update(idx + 1, 1);
            } else {
                if(--freq[idx] == 0) fenwick.update(idx + 1, -1);
            }
        };

        vector<int> res(Q.size(), -1);
        int l = 0, r = -1;
        for(auto& [le,ri,k,idx] : Q) {
            while(l > le) udt(--l,1);
            while(r < ri) udt(++r, 1);
            while(l < le) udt(l++, -1);
            while(r > ri) udt(r--, -1);

            if(fenwick.total() < k) continue;
            
            res[idx] = S[fenwick.kth(k) - 1];
        }
        return res;
    }
};