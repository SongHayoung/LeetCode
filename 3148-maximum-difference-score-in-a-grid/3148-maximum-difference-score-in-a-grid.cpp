class Solution {
public:
    int maxScore(vector<vector<int>>& A) {
        vector<int> dp(A[0].size(), -1e6);
        int res = INT_MIN;
        bool fl = false;
        for(int i = A.size() - 1; i >= 0; i--) {
            for(int j = A[0].size() - 1; j >= 0; j--) {
                if(j + 1 < A[0].size()) dp[j] = max(dp[j], dp[j+1]);
                if(fl) res = max(res, dp[j] - A[i][j]);
                fl = true;
                dp[j] = max(dp[j], A[i][j]);
            }
        }
        return res;
    }
};
