class Solution {
    int dp[1ll<<16];
    bool bit(int x, int b) {
        return (x>>b) & 1;
    }
    int helper(int mask, unordered_set<int>& bits) {
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = 0;
        for(auto& b : bits) {
            if(mask & b) continue;
            if(helper(mask | b, bits)) return res = 1;
        }
        return res;
    }
public:
    bool canPartitionKSubsets(vector<int>& A, int k) {
        int sum = accumulate(begin(A), end(A), 0);
        if(sum % k) return false;
        memset(dp,-1,sizeof dp);
        unordered_set<int> bits;
        dp[(1ll<<A.size()) - 1] = 1;
        int target = sum / k;
        for(int i = 0; i < 1ll<<A.size(); i++) {
            int now = 0;
            for(int j = 0; j < A.size(); j++) {
                if(bit(i,j)) now += A[j];
            }
            if(now == target) bits.insert(i);
        }
        return helper(0,bits);
    }
};