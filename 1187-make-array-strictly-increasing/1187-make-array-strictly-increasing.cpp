class Solution {
    int dp[2001][2001][2], INF = 2020;
    int helper(vector<int>& A, vector<int>& B, bool changed, int i, int j) {
        if(i == A.size()) return 0;
        
        int prev = i == 0 ? INT_MIN : changed ? B[j] : A[i-1];
        j = upper_bound(begin(B), end(B), prev) - begin(B);
        
        if(dp[i][j][changed] != -1) return dp[i][j][changed];
        int& res = dp[i][j][changed] = INF;
        
        if(j < B.size())
            res = helper(A,B,true,i+1,j) + 1;
        if(prev < A[i])
            res = min(res, helper(A,B,false,i+1, j));
        
        return res;
    }
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        memset(dp,-1,sizeof(dp));
        int res = helper(arr1,arr2,false,0,0);
        return res >= INF ? -1 : res;
    }
};