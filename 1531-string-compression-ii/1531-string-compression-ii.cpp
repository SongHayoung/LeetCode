#define INF 1e9
class Solution {
    int dp[101][101];
    int len(int x) {
        return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; 
    }
    int helper(string& s, int n, int p, int k) {
        if(k < 0) return INF;
        if(n == p or n - p <= k) return 0;
        int& res = dp[p][k];
        if(res != -1) return res;
        res = INF;
        
        int freq[26] = {}, best = 0;
        
        for(int i = p; i < n; i++) {
            best = max(best, ++freq[s[i]-'a']);
            res = min(res, 1 + len(best) + helper(s, n, i + 1, k - (i - p + 1 - best)));
        }
        return res;
    }
public:
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof dp);
        return helper(s, s.length(), 0, k);
    }
};