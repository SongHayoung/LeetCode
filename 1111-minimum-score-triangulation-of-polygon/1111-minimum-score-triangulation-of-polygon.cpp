class Solution {
    int dp[51][51];
    const int INF = 987654321;
    int helper(vector<int>& A, int s, int e) {
        if(dp[s][e] != -1) return dp[s][e];
        dp[s][e] = INF;
        for(int i = s + 1; i < e; i++) {
            dp[s][e] = min(dp[s][e],
                           helper(A,s,i) + helper(A,i,e) + A[s] * A[e] * A[i]
                          );
        }
        if(dp[s][e] == INF) dp[s][e] = 0;
        return dp[s][e];
    }
public:
    int minScoreTriangulation(vector<int>& values) {
        memset(dp, -1, sizeof dp);
        
        return helper(values, 0, values.size() - 1);
    }
};