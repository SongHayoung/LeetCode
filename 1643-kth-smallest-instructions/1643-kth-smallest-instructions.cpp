class Solution {
    long long dp[33][33];
public:
    string kthSmallestPath(vector<int>& A, int k) {
        for(int i = 0; i <= 32; i++) dp[i][0] = dp[i][i] = 1;
        for(int i = 1; i <= 32; i++) {
            for(int j = 1; j < i; j++) {
                dp[i][j] = min(INT_MAX * 1ll, dp[i-1][j-1] + dp[i-1][j]);
            }
        }
        int tot = A[0] + A[1], bad = A[0];
        string res = "";
        k -= 1;
        for(int i = 0; i < tot; i++) {
            int n = tot - i;
            if(bad == 0) {
                return res + string(n,'H');
            }
            if(n == bad) {
                return res + string(n, 'V');
            }
            long long count = dp[n-1][bad];
            if(count <= k) {
                k -= count;
                res.push_back('V');
                bad--;
            } else {
                res.push_back('H');
            }
        }
        return res;
    }
};