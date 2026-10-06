
class Solution {
public:
    int minDays(int n) {
        vector<long long> dp(n+1, INT_MAX);
        dp[0] = -1;
        for(int day = 0; day < n; day++) {
            for(int cons = 1, sum = 0; day + sum + cons <= n; cons++) {
                sum += cons;
                dp[day + sum] = min(dp[day + sum], dp[day] + 1 + cons);
            }
        }
        
        return dp[n];
    }
};
