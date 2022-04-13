class Solution {
    //city, week
    int dp[101][101];
    int solution(int& k, vector<vector<int>>& f, vector<vector<int>>& d, int c, int w) {
        if(k == w) return 0;
        if(dp[c][w] != -1) return dp[c][w];
        dp[c][w] = d[c][w] + solution(k,f,d,c,w+1);
        for(int i = 0; i < f[c].size(); i++) {
            if(f[c][i])
                dp[c][w] = max(dp[c][w], d[c][w] + solution(k,f,d,i,w+1));
        }
        return dp[c][w];
    }
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int k = days[0].size(), n = flights.size();
        memset(dp, -1, sizeof(dp));
        int res = solution(k,flights,days,0,0);
        for(int i = 1; i < n; i++) {
            if(flights[0][i])
                res = max(res,solution(k,flights,days,i,0));
        }
        return res;
    }
};