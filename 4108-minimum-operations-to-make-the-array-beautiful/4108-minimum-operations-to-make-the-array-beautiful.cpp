
long long dp[101][101];
class Solution {
    long long helper(vector<int>& A, int at, int target) {
        if(A[at] > target) return INT_MAX;
        if(at == 0) return target != A[0] ? INT_MAX : 0;
        if(dp[at][target] != -1) return dp[at][target];
        long long& res = dp[at][target] = INT_MAX, diff = target - A[at], sq = sqrt(target);
        for(int i = 1; i <= sq; i++) {
            if(target % i) continue;
            res = min(res, diff + min(helper(A,at-1,i), helper(A,at-1,target / i)));
        }
        return res;
    }
public:
    int minOperations(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        long long res = LLONG_MAX;
        for(int i = nums.back(); i <= 100; i++) {
            res = min(res, helper(nums, nums.size() - 1, i));
        }
        return res;
    }
};
