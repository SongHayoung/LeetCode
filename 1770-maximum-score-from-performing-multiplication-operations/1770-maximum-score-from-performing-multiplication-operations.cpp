class Solution {
    int dfs(vector<int>& nums, vector<int>& mul, vector<vector<int>>& dp, vector<vector<bool>>& visit, int i, int j) {
        if(j >= mul.size())
            return 0;
        //j for mul
        //i for nums
        if(!visit[j][i]) {
            int k = nums.size() - 1 - (j - i); 
            dp[j][i] = max(nums[i] * mul[j] + dfs(nums, mul, dp, visit, i + 1, j + 1),
                    nums[k] * mul[j] + dfs(nums, mul, dp, visit, i, j + 1));
            
            visit[j][i] = true;
        }
        return dp[j][i];
    }
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        vector<vector<int>> dp(multipliers.size() + 1, vector<int>(multipliers.size() + 1));
        vector<vector<bool>> visit(multipliers.size() + 1, vector<bool>(multipliers.size() + 1, false));
        return dfs(nums, multipliers, dp, visit, 0, 0);
    }
};