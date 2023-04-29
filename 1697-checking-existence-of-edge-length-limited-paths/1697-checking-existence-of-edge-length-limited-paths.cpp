class Solution {
    vector<int> g;
    int find(int n) {
        return g[n] == n? n : g[n] = find(g[n]);
    }
    void uni(int a, int b) {
        int pa = find(a), pb = find(b);
        g[pa] = g[pb] = min(pa, pb);
    }
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        g = vector<int>(n);
        for(int i = 0; i < n; i++) g[i] = i;
        priority_queue<array<int,3>, vector<array<int,3>>, greater<array<int,3>>> e;
        for(auto edge : edgeList) {
            e.push({edge[2],edge[1],edge[0]});
        }
        vector<bool> res(queries.size());
        
        priority_queue<array<int,4>, vector<array<int,4>>, greater<array<int,4>>> q;
        for(int i = 0; i < queries.size(); i++) {
            q.push({queries[i][2], i, queries[i][0], queries[i][1]});
        }
        while(!q.empty()) {
            auto [limit, index, a, b] = q.top(); q.pop();
            while(!e.empty() and e.top()[0] < limit) {
                auto [cost, f, t] = e.top(); e.pop();
                uni(f,t);
            }
            res[index] = find(a) == find(b);
        }
        
        return res;
    }
};