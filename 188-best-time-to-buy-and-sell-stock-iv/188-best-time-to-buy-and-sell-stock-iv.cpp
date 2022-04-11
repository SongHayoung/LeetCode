class Solution {
    int dp[101][1001];
    int mi[1001];
    int solution(int &k, vector<int>& p, int t, int s) {
        if(s == p.size()) return 0;
        if(t == k) return 0;
        if(dp[t][s] != -1) return dp[t][s];
        dp[t][s] = 0;
        
        int cost = p[s];
        
        for(int i = s + 1; i <= mi[i]; i++) {
            dp[t][s] = max(dp[t][s], p[i] - cost + solution(k,p,t + 1, i + 1));
            cost = min(cost, p[i]);
        }
        
        return dp[t][s];
    }
public:
    int maxProfit(int k, vector<int>& p) {
        int idx = p.size() - 1;
        for(int i = p.size() - 1; i >= 0; i--) {
            mi[i] = idx;
            idx = min(mi[i], mi[idx]);
        }
        memset(dp, -1, sizeof(dp));
        return solution(k,p,0,0);
    }
};