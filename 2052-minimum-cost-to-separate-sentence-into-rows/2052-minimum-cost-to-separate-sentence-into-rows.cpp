class Solution {
    long long dp[5050];
    long long helper(string& s, int k, int p) {
        if(dp[p] != -1) return dp[p];
        int n = s.length();
        if(n - k <= p) return 0;
        long long& res = dp[p] = INT_MAX;
        for(int i = p; i <= p + k; i++) {
            if(s[i] == ' ') {
                res = min(res, (k - (i - p)) * (k - (i - p)) + helper(s,k,i+1));
            }
        }
        return res;
    }
public:
    int minimumCost(string sentence, int k) {
        memset(dp,-1,sizeof dp);
        
        return helper(sentence, k, 0);
    }
};