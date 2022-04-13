class Solution {
public:
    bool isBipartite(vector<vector<int>>& g) {
        int n = g.size();
        vector<int> gr(n, -1);
        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(gr[i] != -1) continue;
            gr[i] = 0;
            q.push(i);
            while(!q.empty()) {
                auto u = q.front(); q.pop();
                for(auto& v : g[u]) {
                    if(gr[v] == gr[u]) return false;
                    if(gr[v] == -1) {
                        gr[v] = gr[u] ? 0 : 1;
                        q.push(v);
                    }
                }
            }
        }
        return true;
    }
};