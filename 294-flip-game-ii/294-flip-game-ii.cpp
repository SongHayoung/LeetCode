class Solution {
    unordered_map<string, bool> dp[2];
    bool solution(string& status, bool turn) {
        if(dp[turn].count(status)) return dp[turn][status];
        dp[turn][status] = !turn;
        for(int i = 0; i < status.length() - 1 and dp[turn][status] == !turn; i++) {
            if(status[i] == '+' and status[i+1] =='+') {
                status[i] = status[i+1] = '-';
                bool res = solution(status,!turn);
                status[i] = status[i+1] = '+';
                dp[turn][status] = res;
            }
        }
        return dp[turn][status];
    }
public:
    bool canWin(string currentState) {
        return solution(currentState, true);
    }
};