
class Solution {
public:
    int minLargest(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(m+1,{(n + 1) * (m + 1) * 2, (n + 1) * (m + 1) * 2}));
        dp[0][0] = {0,0};
        auto helper = [&](int x, int fl) {
            if(x % 2 == fl % 2) return x + 2;
            return x + 1;
        };
        auto udt = [&](int i, int j, int x) {
            if(x % 2 == 0) dp[i][j].second = min(dp[i][j].second, x);
            else dp[i][j].first = min(dp[i][j].first, x);
        };
        for(int i = 0; i <= n; i++) {
            for(int j = 0; j <= m; j++) {
                if(i < n) {
                    int a = helper(dp[i][j].first, A[i]);
                    int b = helper(dp[i][j].second, A[i]);
                    udt(i+1,j,a);
                    udt(i+1,j,b);
                }
                if(j < m) {
                    int a = helper(dp[i][j].first, B[j]);
                    int b = helper(dp[i][j].second, B[j]);
                    udt(i,j+1,a);
                    udt(i,j+1,b);
                }
            }
        }
        return min(dp[n][m].first, dp[n][m].second);
    }
};
