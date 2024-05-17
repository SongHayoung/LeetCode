class Solution {
    int helper(int u, int v, vector<pair<int,int>>& adj1, vector<pair<int,int>>& adj2, int x) {
        int res = -1;
        for(auto& [cost1, who1] : adj1) {
            if(who1 == v) continue;
            for(auto& [cost2, who2] : adj2) {
                if(who1 == who2) continue;
                if(who2 == u) continue;
                res = max(res, cost1 + cost2 + x);
            }
        }
        
        return res;
    }
public:
    int maximumScore(vector<int>& A, vector<vector<int>>& E) {
        int n = A.size();
        vector<vector<pair<int,int>>> adj(n);
        for(auto& e : E) {
            int u = e[0], v = e[1];
            adj[u].push_back({A[v],v});
            adj[v].push_back({A[u],u});
            if(adj[u].size() > 3) {
                sort(rbegin(adj[u]), rend(adj[u]));
                adj[u].pop_back();
            }
            if(adj[v].size() > 3) {
                sort(rbegin(adj[v]), rend(adj[v]));
                adj[v].pop_back();
            }
        }
        int res = -1;
        for(auto& e : E) {
            int u = e[0], v = e[1];
            res = max(res, helper(u,v,adj[u],adj[v],A[u] + A[v]));
        }
        return res;
    }
};