class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        vector<int> pos;
        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i]) pos.push_back(i);
        }
        if(pos.size() & 1) return -1;
        vector<vector<long long>> dp(pos.size() + 1, vector<long long>(pos.size() + 2, 1e9));
        dp[0][0] = 0;
        for(int i = 0; i < pos.size(); i++) {
            for(int j = 0; j <= pos.size(); j++) {
                if(j == 0) {
                    dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
                } else {
                    dp[i+1][j-1] = min(dp[i+1][j-1], dp[i][j] + x);
                }
                if(i + 1 < pos.size()) {
                    dp[i+2][j] = min(dp[i+2][j], dp[i][j] + min(x, pos[i+1] - pos[i]));
                }
            }
        }
        return dp[pos.size()][0];
    }
};