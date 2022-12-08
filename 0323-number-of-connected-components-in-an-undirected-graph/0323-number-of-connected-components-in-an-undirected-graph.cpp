class Solution {
    int find(vector<int>& g, int u) {
        return g[u] == u ? u : g[u] = find(g,g[u]);
    }
    void uni(vector<int>& g, int u, int v) {
        int pu = find(g,u), pv = find(g,v);
        g[pu] = g[pv] = min(pu, pv);
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> g(n);
        for(int i = 0; i < n; i++) g[i] = i;
        for(auto e : edges) {
            uni(g,e[0],e[1]);
        }
        unordered_set<int> gr;
        for(int i = 0; i < n; i++)
            gr.insert(find(g,i));
        
        return gr.size();
    }
};