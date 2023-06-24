class Solution {
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        vector<vector<long long>> dp(26,vector<long long>(26,INT_MAX));
        dp[words[0].front()-'a'][words[0].back()-'a'] = words[0].length();
        for(int i = 1; i < words.size(); i++) {
            int a = words[i].front() - 'a', b = words[i].back() - 'a', len = words[i].length();
            vector<vector<long long>> dpp(26,vector<long long>(26,INT_MAX));
            for(int x = 0; x < 26; x++) for(int y = 0; y < 26; y++) {
                dpp[a][y] = min(dpp[a][y], len + dp[x][y] - (b == x));
                dpp[x][b] = min(dpp[x][b], len + dp[x][y] - (a == y));
            }
            swap(dp,dpp);
        }
        long long res = LLONG_MAX;
        for(int i = 0; i < 26; i++) for(int j = 0; j < 26; j++) res = min(res, dp[i][j]);
        return res;
    }
};
