class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int res = 0, n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < max(m,n); i++) {
            if(i < n)
                for(int j = i; j < m; j++) {
                    if(matrix[i][j] != '1') continue;
                    if(!i || !j) dp[i][j] = matrix[i][j] & 0b1111;
                    else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                    res = max(dp[i][j], res);
                }
            if(i < m)
                for(int j = i + 1; j < n; j++) {
                    if(matrix[j][i] != '1') continue;
                    if(!i || !j) dp[j][i] = matrix[j][i] & 0b1111;
                    else dp[j][i] = min(dp[j-1][i-1], min(dp[j-1][i], dp[j][i-1])) + 1;
                    res = max(dp[j][i], res);
                }
        }
        return res * res;
    }
};
