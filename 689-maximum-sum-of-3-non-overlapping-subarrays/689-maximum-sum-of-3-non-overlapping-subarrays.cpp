class Solution {
    long getSum(vector<long>& prefixSum, int i, int k) {
        return prefixSum[i + k] - prefixSum[i];
    }
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long> prefixSum(n + 1, 0);
        for(int i = 0; i < n; i++)
            prefixSum[i + 1] = prefixSum[i] + nums[i];

        vector<vector<pair<int,vector<int>>>> dp(3, vector<pair<int,vector<int>>>(n+1, {0,{}}));
        
        for(int i = n - k; i >= 0; i--) {
            long sum = getSum(prefixSum, i, k);
            if(sum >= dp[0][i+1].first) {
                dp[0][i] = {sum, {i}};
            } else {
                dp[0][i] = dp[0][i + 1];
            }
            if(i  <= n - 2 * k) {
                long secondSum = dp[0][i+k].first + sum;
                if(secondSum >= dp[1][i+1].first) {
                    dp[1][i] = {secondSum, {i, dp[0][i+k].second[0]}};
                } else {
                    dp[1][i] = dp[1][i+1];
                }
            }
            
            if(i  <= n - 3 * k) {
                long thirdSum = dp[1][i+k].first + sum;
                if(thirdSum >= dp[2][i+1].first) {
                    dp[2][i] = {thirdSum, {i, dp[1][i+k].second[0], dp[1][i+k].second[1]}};
                } else {
                    dp[2][i] = dp[2][i+1];
                }
            }
        }
        return dp[2][0].second;
    }
};