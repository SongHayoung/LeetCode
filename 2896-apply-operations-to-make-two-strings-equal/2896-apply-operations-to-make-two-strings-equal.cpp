class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> p;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) p.push_back(i);
        }
        if(p.size() & 1) return -1;
        vector<vector<long long>> dp(p.size() + 2, vector<long long>(p.size() + 2, 1e9));
        dp[0][0] = 0;
        for(int i = 0; i < p.size(); i++) {
            for(int j = 0; j <= p.size(); j++) {
                if(j == 0) {
                    dp[i+1][1] = min(dp[i+1][1], dp[i][j]);
                } else {
                    dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + x);
                }
                if(i + 1 < p.size()) {
                    dp[i+2][j] = min(dp[i+2][j], dp[i][j] + min(p[i+1] - p[i], x));
                }
            }
        }
        return dp[p.size()][0];
    }
};