class Solution {
    unordered_map<int,int> deps;
    int C[51];
    vector<int> adj[101010];
    vector<int> who[51];
    int best(int ori, int x) {
        if(ori == -1) return x;
        if(deps[ori] > deps[x]) return ori;
        return x;
    }
    void dfs(int u, vector<int>& res, vector<int>& A, int par, int d = 0) {
        deps[u] = d;
        for(auto& x : who[A[u]]) {
            if(C[x] == -1) continue;
            res[u] = best(res[u], C[x]);
        }
        int x = C[A[u]];
        C[A[u]] = u;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs(v,res,A,u,d+1);
        }
        C[A[u]] = x;
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        for(int i = 0; i < nums.size(); i++) adj[i].clear();
        for(int i = 0; i <= 50; i++) who[i].clear();
        for(int i = 1; i <= 50; i++) {
            for(int j = i; j <= 50; j++) {
                if(__gcd(i,j) == 1) {
                    who[i].push_back(j);
                    who[j].push_back(i);
                }
            }
        }
        memset(C,-1,sizeof C);
        deps = {};
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res(nums.size(),-1);
        dfs(0,res,nums,-1);
        return res;
    }
};