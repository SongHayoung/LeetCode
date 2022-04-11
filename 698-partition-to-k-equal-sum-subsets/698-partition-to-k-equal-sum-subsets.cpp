class Solution {
    int dp[1<<16];
    vector<int> combs;
    void buildComb(vector<int>& A, int comb, int sum, unordered_set<int>& vis) {
        if(!sum) {combs.push_back(comb);}
        else if(vis.count(comb)) return;
        else {
            vis.insert(comb);
            for(int i = 0; i < A.size() and A[i] <= sum; i++) {
                if(comb & (1<<i)) continue;
                buildComb(A,comb | (1<<i), sum - A[i], vis);
            }
        }
    }
    int helper(vector<int>& A, int mask) {
        if(dp[mask] != -1) return dp[mask];
        dp[mask] = 0;
        for(auto& comb : combs) {
            if(comb & mask) continue;
            if(helper(A,mask | comb)) return 1;
        }
        return 0;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(begin(nums),end(nums),0), n;
        if(sum % k) return false;
        sum /= k;
        sort(begin(nums),end(nums));
        if(nums.back() > sum) return false;
        while(!nums.empty() and nums.back() == sum) nums.pop_back();
        n = nums.size();
        memset(dp,-1,sizeof(dp));
        buildComb(nums, 0, sum, unordered_set<int>() = {});
        dp[(1<<n) - 1] = 1;
        return helper(nums, 0);
    }
};