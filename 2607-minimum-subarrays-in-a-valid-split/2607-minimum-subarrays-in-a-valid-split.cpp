long long dp[1010];
class Solution {
    long long helper(vector<int>& A, int pos) {
        if(pos == A.size()) return 0;
        if(dp[pos] != -1) return dp[pos];
        long long& res = dp[pos] = INT_MAX;
        for(int i = pos; i < A.size(); i++) {
            int g = __gcd(A[i],A[pos]);
            if(g == 1) continue;
            res = min(res, 1 + helper(A,i+1));
        }
        return res;
    }
public:
    int validSubarraySplit(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        long long res = helper(nums, 0);
        return res > nums.size() ? -1 : res;
    }
};