//Absent : 1, 0 only
//Late : not consequtive 3times (2, 1, 0 only)
//range : 0 ... 100000
class Solution {
    int dp[100001][2][3];
    int mod = 1e9 + 7;
    int solution(int day, int absent, int late) {
        if(dp[day][absent][late] != -1) return dp[day][absent][late];
        dp[day][absent][late] = solution(day + 1, absent, 0); //attendance;
        if(!absent) {
            dp[day][absent][late] = (dp[day][absent][late] + solution(day + 1, absent + 1, 0)) % mod; //if can absent, absent today;
        }
        if(late < 2) {
            dp[day][absent][late] = (dp[day][absent][late] + solution(day + 1, absent, late + 1)) % mod; //if can absent, absent today;
        }
        return dp[day][absent][late];
    }
public:
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
        dp[n][0][0] = dp[n][0][1] = dp[n][0][2] = dp[n][1][0] = dp[n][1][1] = dp[n][1][2] = 1;
        return solution(0,0,0);
    }
};