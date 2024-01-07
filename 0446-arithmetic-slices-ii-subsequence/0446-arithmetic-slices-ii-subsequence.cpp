class Solution {
    vector<unordered_map<long,int>> dp;
    unordered_map<long, vector<int>> indexes;
    int helper(vector<int>& nums, int p, long diff) {
        if(dp[p].count(diff)) return dp[p][diff];
        dp[p][diff] = 1;
        long target = nums[p] + diff;
        if(indexes.count(target)) {
            auto up = upper_bound(indexes[target].begin(), indexes[target].end(), p);
            for(auto it = up; it != indexes[target].end(); it++) {
                dp[p][diff] += helper(nums, *it, diff);
            }
        }
        return dp[p][diff];
    }
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(), res = 0;
        dp = vector<unordered_map<long,int>>(n);
        
        for(int i = 0; i < n; i++)
            indexes[nums[i]].push_back(i);
        for(int i = n - 1; i >= 0; i--) {
            for(int j = i + 1; j < n; j++) {
                long diff = 1l * nums[j] - 1l* nums[i];
                long target = 1l*nums[j] + diff;
                if(indexes.count(target)) {
                    auto up = upper_bound(indexes[target].begin(), indexes[target].end(), j);
                    for(auto it = up; it != indexes[target].end(); it++) {
                        res += helper(nums, *it, diff);
                    }
                }
            }
        }
        
        return res;
    }
};