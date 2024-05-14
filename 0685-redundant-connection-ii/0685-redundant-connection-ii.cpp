class Solution {
    vector<int> uf;
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        uf[pu] = uf[pv] = min(pu,pv);
    }
    int check(vector<vector<int>>& E, int x) {
        uf = vector<int>(E.size() + 1);
        for(int i = 0; i < uf.size(); i++) uf[i] = i;
        for(int i = 0; i < E.size(); i++) {
            if(i == x) continue;
            uni(E[i][0], E[i][1]);
        }
        for(int i = 1; i < uf.size(); i++) if(find(i) != 1) {
            return -1;
        }
        return x;
    }
    int dup(vector<vector<int>>& E) {
        vector<int> deg(E.size() + 1, -1);
        for(int i = 0; i < E.size(); i++) {
            int u = E[i][0], v = E[i][1];
            if(deg[v] == -1) deg[v] = i;
            else {
                return max(check(E,deg[v]), check(E,i));
            }
        }
        return -1;
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& E) {
        int x = dup(E);
        if(x != -1) return E[x];
        uf = vector<int>(E.size() + 1);
        for(int i = 0; i < uf.size(); i++) uf[i] = i;
        for(int i = 0; i < E.size(); i++) {
            int u = E[i][0], v = E[i][1];
            if(find(u) == find(v)) return E[i];
            uni(u,v);
        }
        return {};
    }
};