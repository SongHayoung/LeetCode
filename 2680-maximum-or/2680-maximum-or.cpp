class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        vector<long long> dp(k+1, 0);
        for(auto n : nums) {
            vector<long long> dpp(k + 1, 0);
            long long x = n;
            for(int i = 0; i <= k; i++) {
                for(int j = 0; j <= k - i; j++) {
                    dpp[i+j] = max(dpp[i+j], dp[i] | (x<<j));
                }
            }
            
            swap(dp, dpp);
        }
        
        
        return *max_element(begin(dp), end(dp));
    }
};

