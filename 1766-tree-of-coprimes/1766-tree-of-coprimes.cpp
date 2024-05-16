class Solution {
    unordered_map<int,int> deps;
    vector<int> adj[101010];
    int best(int ori, int x) {
        if(ori == -1) return x;
        if(deps[ori] > deps[x]) return ori;
        return x;
    }
    void dfs(int u, vector<int> C, vector<int>& res, vector<int>& A, int par, int d = 0) {
        deps[u] = d;
        for(int i = 50; i >= 1; i--) {
            if(C[i] == -1) continue;
            if(__gcd(i,A[u]) == 1) {
                res[u] = best(res[u], C[i]);
            }
        }
        C[A[u]] = u;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs(v,C,res,A,u,d+1);
        }
    }
public:
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        
        vector<int> cop(51,-1);
        for(int i = 0; i < nums.size(); i++) adj[i].clear();
        deps = {};
        for(auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> res(nums.size(),-1);
        dfs(0,cop,res,nums,-1);
        return res;
    }
};