class Solution {
    int findMaximumXOR(unordered_set<int>& a, unordered_set<int>& b) {
        int res = 0;
        for(auto& x : a) for(auto& y : b) res = max(res, x ^ y);
        return res;
    }
public:
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size(), ma = 1<<7;
        vector<unordered_set<int>> dpl(n), dpr(n);
        vector<bitset<252>> dp;

        auto knapsack = [&](int x) {
            for(int i = ma - 1; i; i--) {
                dp[i | x] |= dp[i]<<1;
            }
            dp[x][1] = 1;
        };

        dp = vector<bitset<252>>(ma);
        for(int i = 0; i < nums.size(); i++) {
            knapsack(nums[i]);
            for(int j = 0; j < ma; j++) if(dp[j][k]) dpl[i].insert(j);
        }

        dp = vector<bitset<252>>(ma);
        for(int i = nums.size() - 1; i >= 0; i--) {
            knapsack(nums[i]);
            for(int j = 0; j < ma; j++) if(dp[j][k]) dpr[i].insert(j);
        }
        int res = 0;
        for(int i = k - 1; i + k < nums.size(); i++) {
            res = max(res, findMaximumXOR(dpl[i], dpr[i+1]));
        }
        return res;
    }
};