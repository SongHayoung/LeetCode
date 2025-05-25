vector<int> dp[160][3], adj[160];
class Solution {
    void knapsack(vector<int>& dp, vector<int>& A, vector<int>& B, int from, int to) {
        for(int i = from; i >= to; i--) {
            for(int j = from - i; j >= 0; j--) {
                dp[i+j] = max(dp[i+j], dp[i] + max(A[j], B[j]));
            }
        }
    }
    void dfs(long long u, long long b, vector<int>& A, vector<int>& B) {
        for(auto& v : adj[u]) dfs(v,b,A,B);
        int half = A[u] / 2, ori = A[u];
        vector<int> &buy = dp[u][0], &notBuy = dp[u][1], &dis = dp[u][2];
        buy = notBuy = dis = vector<int>(b + 1, -1e9);
        buy[0] = notBuy[0] = dis[0] = 0;
        if(ori <= b) buy[ori] = -ori + B[u];
        if(half <= b) dis[half] = -half + B[u];
        for(auto& v : adj[u]) {
            knapsack(notBuy, dp[v][0], dp[v][1], b, 0);
            knapsack(buy, dp[v][1], dp[v][2], b, ori);
            knapsack(dis, dp[v][1], dp[v][2], b, half);
        }
    }
public:
    int maxProfit(int n, vector<int>& present, vector<int>& future, vector<vector<int>>& hierarchy, int budget) {
        for(int i = 0; i < n; i++) adj[i].clear();
        for(auto& h : hierarchy) {
            int u = h[0] - 1, v = h[1] - 1;
            adj[u].push_back(v);
        }
        dfs(0,budget, present, future);
        return max(*max_element(begin(dp[0][0]), end(dp[0][0])), *max_element(begin(dp[0][1]), end(dp[0][1])));
    }
};
