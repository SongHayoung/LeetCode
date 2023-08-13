class Solution {
    int dp[101010];
    bool eqtwo(vector<int>& A, int p) {
        if(p + 2 > A.size()) return false;
        return A[p] == A[p+1];
    }
    bool eqthree(vector<int>& A, int p) {
        if(p + 3 > A.size()) return false;
        return A[p] == A[p+1] and A[p] == A[p + 2];
    }
    bool incthree(vector<int>& A, int p) {
        if(p + 3 > A.size()) return false;
        return A[p] + 1 == A[p+1] and A[p] + 2 == A[p + 2];
    }
    int helper(vector<int>& A, int p) {
        if(p == A.size()) return 1;
        if(dp[p] != -1) return dp[p];
        int& res = dp[p] = 0;
        if(eqtwo(A,p)) res |= helper(A, p + 2);
        if(eqthree(A,p))  res |= helper(A, p + 3);
        if(incthree(A,p)) res |= helper(A, p + 3);
        return res;
    }
public:
    bool validPartition(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        return helper(nums, 0);
    }
};