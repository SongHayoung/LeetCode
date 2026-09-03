
class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<long long> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        for(auto& n : nums) {
            unordered_map<int,int> cost;
            for(int val = n, c = 0; val <= sum; val *= 2, c++) {
                cost[val] = c;
            }
            for(int val = n, c = 0; val; val /= 2, c++) {
                cost[val] = c;
            }
            vector<long long> dpp = dp;
            for(auto& [k,v] : cost) {
                for(int s = sum; s >= k; s--) {
                    dpp[s] = min(dpp[s], dp[s-k] + v);
                }
            }
            swap(dp,dpp);
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
