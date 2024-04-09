class Solution {
    vector<int> uf;
    vector<int> bits;
    int find(int u) {
        return uf[u] == u ? u : uf[u] = find(uf[u]);
    }
    void uni(int u, int v, int w) {
        int pu = find(u), pv = find(v);
        bits[pu] = bits[pv] = bits[pu] & bits[pv] & w;
        uf[pu] = uf[pv] = min(pu, pv);
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        uf = vector<int>(n);
        bits = vector<int>(n,INT_MAX);
        for(int i = 0; i < n; i++) uf[i] = i;
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            uni(u,v,w);
        }
        vector<int> res;
        for(auto& q : query) {
            int u = q[0], v = q[1];
            int pu = find(u), pv = find(v);
            if(pu != pv) res.push_back(-1);
            else if(u == v) res.push_back(0);
            else {
                int now = bits[pu];
                if(now == INT_MAX) now = 0;
                res.push_back(now);
            }
        }
        return res;
    }
};