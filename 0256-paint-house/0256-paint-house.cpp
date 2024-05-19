class Solution {
public:
    int minCost(vector<vector<int>>& A) {
        vector<int> dp = A[0];
        for(int i = 1; i < A.size(); i++) {
            vector<int> dpp(3,INT_MAX);
            dpp[0] = A[i][0] + min(dp[1], dp[2]);
            dpp[1] = A[i][1] + min(dp[0], dp[2]);
            dpp[2] = A[i][2] + min(dp[0], dp[1]);
            swap(dp,dpp);
        }
        return *min_element(begin(dp),end(dp));
    }
};