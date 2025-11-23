class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp{0,INT_MIN,INT_MIN};
        for(auto& x : nums) {
            vector<int> dpp = dp;
            for(int i = 0; i < 3; i++) {
                if(dp[i] < 0) continue;
                int d = (dp[i] + x) % 3;
                dpp[d] = max(dpp[d], dp[i] + x);
            }
            
            swap(dp,dpp);
        }
        return dp[0];
    }
};