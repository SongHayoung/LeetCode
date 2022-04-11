class Solution {
    vector<int> g;
    int find(int n) {
        return g[n] == n ? n : g[n] = find(g[n]);
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n - 1) return false;
        g = vector<int>(n,0);
        for(int i = 0; i < n; i++) g[i] = i;
        for(auto e : edges) {
            int n1 = find(e[0]), n2 = find(e[1]);
            if(n1 == n2) return false;
            g[n1] = g[n2] = min(n1, n2);
        }
        return true;
        //return !accumulate(g.begin(), g.end(), 0, [&](int s, int n) {return s + find(n);});
    }
};