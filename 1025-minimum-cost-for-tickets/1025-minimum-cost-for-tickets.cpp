class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size() + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 0; i < days.size(); i++) {
            dp[i+1] = dp[i] + costs[0]; //one day ticket
            auto sevenDaysBefore = upper_bound(days.begin(), days.begin() + i, days[i] - 7);
            if(sevenDaysBefore == begin(days)) {
                dp[i+1] = min(dp[i+1], costs[1]);
            } else {
                int dis = sevenDaysBefore - begin(days);
                dp[i + 1] = min(dp[i+1], costs[1] + dp[dis]);
            }
            auto monthBefore = upper_bound(days.begin(), days.begin() + i, days[i] - 30);
            if(monthBefore == begin(days)) {
                dp[i+1] = min(dp[i+1], costs[2]);
            } else {
                int dis = monthBefore - begin(days);
                dp[i+1] = min(dp[i+1], costs[2] + dp[dis]);
            }
        }
        return dp.back();
    }
};