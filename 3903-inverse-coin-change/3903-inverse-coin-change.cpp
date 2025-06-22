
class Solution {
public:
    vector<int> findCoins(vector<int>& numWays) {
        vector<int> res;
        vector<int> dp(numWays.size() + 1);
        dp[0] = 1;
        for(int i = 0; i < numWays.size(); i++) {
            if(numWays[i] == dp[i+1]) continue;
            if(numWays[i] - dp[i+1] == 1) {
                res.push_back(i+1);
                for(int j = i + 1; j < dp.size(); j++) dp[j] += dp[j-(i+1)];
            } else return {};
        }
        return res;
    }
};