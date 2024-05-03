class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> adj(n);
        int res = 0;
        for(auto& t : trust) {
            int u = t[0] - 1, v = t[1] - 1;
            if(adj[u] == n - 1) {
                res ^= u;
            }
            adj[u] = -1;
            if(adj[v] != -1) {
                if(++adj[v] == n - 1) res ^= v;
            }
        }
        if(adj[res] == n - 1) return res + 1;
        return -1;
    }
};