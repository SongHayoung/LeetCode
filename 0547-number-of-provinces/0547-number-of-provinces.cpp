class Solution {
    vector<int> g;
    int find(int n) {
        return g[n] == n ? n : g[n] = find(g[n]);
    }
    void uni(int u, int v) {
        int pu = find(u), pv = find(v);
        g[pu] = g[pv] = min(pu,pv);
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        g = vector<int>(n);
        for(int i = 0; i < n; i++) g[i] = i;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(isConnected[i][j])
                    uni(i,j);
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(find(i));
        }
        return s.size();
    }
};