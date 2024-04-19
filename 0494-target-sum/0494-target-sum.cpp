class Solution {
    unordered_map<int,int> dp[20];
    int helper(vector<int>& A, int pos, int sum) {
        if(pos == A.size()) return sum == 0;
        if(dp[pos].count(sum)) return dp[pos][sum];
        return dp[pos][sum] = helper(A,pos + 1, sum + A[pos]) + helper(A, pos + 1, sum - A[pos]);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(nums,0,-target);
    }
};