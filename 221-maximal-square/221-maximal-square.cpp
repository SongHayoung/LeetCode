class Solution {
    int n, m;
    int getOrZero(vector<vector<int>>& matrix, int y, int x) {
        if(0 <= y and y < n and 0<= x and x < m) {
            return matrix[y][x];
        }
        return 0;
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        int res = 0;
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dp[i][j] += getOrZero(dp, i - 1, j) + getOrZero(dp, i , j - 1) - getOrZero(dp, i - 1, j - 1) + (matrix[i][j] == '1');
            }
        }
        
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                for(int k = res;;k++) {
                    int area = dp[i][j] - getOrZero(dp, i-k, j) - getOrZero(dp, i, j - k) + getOrZero(dp, i - k, j - k);
                    if(area == k * k) {
                        res = k;
                    } else break;
                }
            }
        }
        return res * res;
    }
};