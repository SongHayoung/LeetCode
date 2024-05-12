class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        vector<int> dp(energy.size());
        for(int i = energy.size()-1; i >= 0; i--) {
            dp[i] += energy[i];
            if(i + k < energy.size()) dp[i] += dp[i+k];
            res = max(res, dp[i]);
        }
        return res;
    }
};