class Solution {
    int helper(int pos, int x, vector<vector<int>>& Q) {
        if(!x) return 0;
        vector<int> dp(x + 1);
        dp[0] = 1;
        for(int i = 0; i < Q.size(); i++) {
            auto l = Q[i][0], r = Q[i][1], v = Q[i][2];
            if(l <= pos and pos <= r) {
                for(int i = x - v; i >= 0; i--) dp[i+v] |= dp[i];
                if(dp.back()) return i+1;
            }
        }
        return INT_MAX;
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int res = -1;
        for(int i = 0; auto& n : nums) {
            res = max(res, helper(i++, n, queries));
        }

        return res == INT_MAX ? -1 : res;
    }
};