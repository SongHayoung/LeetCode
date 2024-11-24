class Solution {
    vector<vector<pair<int,int>>> adj;
    long long helper(vector<pair<long long, long long>>& A, int k) {
        long long sum = 0;
        priority_queue<long long, vector<long long>, greater<>> q;
        while(q.size() < k) q.push(0);
        for(auto& [sel, nsel] : A) {
            sum += nsel;
            q.push(sel-nsel);
            q.pop();
        };
        while(q.size()) {
            sum += q.top(); q.pop();
        }
        return sum;
    }
    pair<long long, long long> dfs(int u, int par, int k, int cost) {
        vector<pair<long long, long long>> sub;
        for(auto& [v,w] : adj[u]) {
            if(v == par) continue;
            sub.push_back(dfs(v,u,k,w));
        }
        long long sum = 0, mi = 0;
        priority_queue<long long, vector<long long>, greater<>> q;
        for(auto& [sel, nsel] : sub) {
            sum += nsel;
            if(sel > nsel) q.push(sel-nsel);
            if(q.size() > k) q.pop();
        };
        if(q.size() == k) mi = q.top();
        while(q.size()) {
            sum += q.top(); q.pop();
        }
        return {sum - mi + cost, sum};
    }
public:
    long long maximizeSumOfWeights(vector<vector<int>>& edges, int k) {
        adj = vector<vector<pair<int,int>>>(edges.size() + 1);
        for(auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        auto [res1,res2] = dfs(0,-1,k,0);
        return max(res1,res2);
    }
};