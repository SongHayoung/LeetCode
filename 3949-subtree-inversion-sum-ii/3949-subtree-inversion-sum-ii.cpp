const int MAX_N = 101010;
const long long NEG_INF = -1e12;
long long dp[MAX_N][55][2], sufs[MAX_N][55][2];
long long dep[MAX_N];
vector<long long> adj[MAX_N];
class Solution {
    void dfs0(long long u, long long par, long long d) {
        dep[u] = d;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            dfs0(v,u,d+1);
        }
    }
    long long dfs1(long long u, long long dis, long long k, long long val, bool fl) {
        long long base = fl ? -val : val, &res = dp[u][dis][fl] = NEG_INF;
        if(adj[u].size() == 1 and dep[adj[u][0]] < dep[u]) {
            return res = max(base, dis ? NEG_INF : -base);
        }
        
        long long sufSum = 0, ddis = max(0ll, dis - 1), dddis = max({0ll, dis-1, k - (ddis + 2)}), ma = NEG_INF;
        
        for(auto& v : adj[u]) {
            if(dep[v] < dep[u]) continue;
            ma = max(ma, dp[v][ddis][fl] - sufs[v][dddis][fl]);
            sufSum += sufs[v][dddis][fl];
        }
        
        res = max(res, base + sufSum + ma);

        if(dis == 0) {
            long long now = -base;
            for(auto& v : adj[u]) {
                if(dep[v] < dep[u]) continue;
                now += dp[v][k-1][!fl];
            }
            res = max(res, now);
        }
        return res;
    }
public:
    long long subtreeInversionSum(vector<vector<int>>& edges, vector<int>& nums, int k) {
        long long n = nums.size();
        for(int i = 0; i < edges.size(); i++) {
            long long u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs0(0,-1,0);
        vector<vector<int>> deps(n);
        for(int i = 0; i < n; i++) deps[dep[i]].push_back(i);
        for(int i = n - 1; i >= 0; i--) {
            while(deps[i].size()) {
                int u = deps[i].back(); deps[i].pop_back();
                for(int j = 0; j <= k; j++) {
                    sufs[u][j][0] = dfs1(u,j,k,nums[u],0);
                    sufs[u][j][1] = dfs1(u,j,k,nums[u],1);
                }

                for(int j = k - 1; j >= 0; j--) {
                    sufs[u][j][0] = max(sufs[u][j][0], sufs[u][j+1][0]);
                    sufs[u][j][1] = max(sufs[u][j][1], sufs[u][j+1][1]);
                }
                adj[u].clear();
            }
        }
        return sufs[0][0][0];
    }
};