class Solution {
    vector<vector<int>> adj;
    
    vector<vector<long long>> dfs(int u, int par, vector<long long>& A, vector<int>& C) {
        vector<vector<long long>> buc(3);
        buc[C[u] >= 0 ? 2 : C[u] == 0 ? 1 : 0].push_back(C[u]);
        
        long long& me = A[u];
        for(auto& v : adj[u]) {
            if(v == par) continue;
            auto sub = dfs(v,u,A,C);
            for(int i = 0; i < 3; i++) {
                while(sub[i].size()) {
                    buc[i].push_back(sub[i].back());
                    sub[i].pop_back();
                }
            }
        }
        sort(begin(buc[0]), end(buc[0]));
        sort(rbegin(buc[2]), rend(buc[2]));
        for(int i = 0; i < 3; i++) {
            while(buc[i].size() > 3) buc[i].pop_back();
        }
        if(buc[0].size() + buc[1].size() + buc[2].size() >= 3) {
            if(buc[2].size() == 3) me = max(me, buc[2][0] * buc[2][1] * buc[2][2]);
            if(buc[0].size() >= 2 and buc[2].size()) me = max(me, buc[0][0] * buc[0][1] * buc[2].front());
        } else me = 1;
        
        return buc;
    }
public:
    vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
        int n = cost.size();
        adj = vector<vector<int>>(n);
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<long long> res(n);
        dfs(0,-1,res,cost);
        return res;
    }
};