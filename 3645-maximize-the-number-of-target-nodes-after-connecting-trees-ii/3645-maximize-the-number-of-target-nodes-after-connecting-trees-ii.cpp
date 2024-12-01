class Solution {
    vector<int> bfs(vector<vector<int>>& E) {
        vector<int> res(E.size() + 1,-1);
        vector<vector<int>> adj(E.size() + 1);
        for(auto& e : E) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        q.push(0); res[0] = 0;
        while(q.size()) {
            int qsz = q.size();
            while(qsz--) {
                int u = q.front(); q.pop();
                for(auto& v : adj[u]) {
                    if(res[v] != -1) continue;
                    res[v] = !res[u];
                    q.push(v);
                }
            }
        }
        return res;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> A = bfs(edges1), B = bfs(edges2);
        unordered_map<int,int> c1,c2;
        for(auto& a : A) c1[a]++;
        for(auto& b : B) c2[b]++;
        int ma = max(c2[0],c2[1]);
        vector<int> res;
        for(int i = 0; i < A.size(); i++) {
            res.push_back(c1[A[i]] + ma);
        }
        return res;
    }
};