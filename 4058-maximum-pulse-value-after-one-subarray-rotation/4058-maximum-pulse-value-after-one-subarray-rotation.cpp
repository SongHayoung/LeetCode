class Solution {
public:
    long long maxValue(vector<int>& nums) {
        long long res = LLONG_MIN;
        for(int ok : {-1,1}) {
            vector<long long> dp(3, -1e16);
            dp[0] = 0;
            for(int i = 0; i < nums.size(); i++) {
                vector<long long> dpp(3, -1e16);
                int sign = i & 1 ? -1 : 1;
                
                dpp[2] = max(dpp[2], dp[2] + sign * nums[i]);
                dpp[1] = max(dpp[1], dp[1] - sign * nums[i]);
                dpp[0] = max(dpp[0], dp[0] + sign * nums[i]);
                
                
                if(ok != sign) {
                    dpp[2] = max(dpp[2], dp[1] - sign * nums[i]);
                } else {
                    dpp[1] = max(dpp[1], dp[0] - sign * nums[i]);
                }

                swap(dp,dpp);
            }
            res = max({res, dp[0], dp[2]});
        }

        return res;
    }
};
