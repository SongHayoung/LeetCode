class Solution {
    int dp[6][16][5001];
    int mod = 1e9 + 7;
    int helper(int n, int con, int num, vector<int>& ma) {
        if(n == 0) return 1;
        int& res = dp[num][con][n];
        if(res != -1) return res;
        res = 0;
        for(int i = 0; i < 6; i++) {
            if(i == num and ma[num] == con) continue;
            res = (res + helper(n-1, i == num ? con + 1 : 1, i, ma)) % mod;
            
        }
        return res;
    }
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        memset(dp,-1,sizeof dp);
        int res = 0;
        for(int i = 0; i < 6; i++) {
            res = (res + helper(n-1, 1, i, rollMax)) % mod;
        }
        return res;
    }
};