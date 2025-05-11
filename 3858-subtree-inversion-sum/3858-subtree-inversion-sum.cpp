const int MAX_N = 101010;
long long dp[MAX_N][55][2], vis[MAX_N][55][2];
vector<long long> adj[MAX_N];
class Solution {
    long long dfs1(long long u, long long par, long long dis, long long k, vector<int>& A, bool fl) {
        if(vis[u][dis][fl]) return dp[u][dis][fl];
        vis[u][dis][fl] = true;
        long long base = fl ? -A[u] : A[u], &res = dp[u][dis][fl] = base;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            res += dfs1(v,u,max(0ll,dis-1), k, A, fl);
        }
        if(dis == 0) {
            long long now = -base;
            for(auto& v : adj[u]) {
                if(v == par) continue;
                now += dfs1(v,u,k-1,k,A,!fl);
            }
            res = max(res, now);
        }
        return res;
    }
public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        memset(vis,0,sizeof vis);
        long long n = nums.size();
        for(int i = 0; i < n; i++) adj[i].clear();
        for(int i = 0; i < edges.size(); i++) {
            long long u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return dfs1(0,-1,0,k,nums,0);
    }
};
