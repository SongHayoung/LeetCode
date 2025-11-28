
int dp[303][303];
class Solution {
    int helper(vector<int>& A, int l, int r) {
        if(l + 1 >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int& res = dp[l][r] = 0;
        for(int i = l + 1; i < r; i++) {
            res = max(res, A[l] * A[i] * A[r] + helper(A,l,i) + helper(A,i,r));
        }
        return res;
    }
public:
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        vector<int> A{1};
        for(auto& n : nums) if(n) A.push_back(n);
        A.push_back(1);
        return helper(A,0,A.size() - 1);
    }
};
