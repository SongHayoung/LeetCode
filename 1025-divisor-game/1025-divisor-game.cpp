class Solution {
    int dp[1001][2];
    int solution(int n, bool alice) {
        if(dp[n][alice] != -1) return dp[n][alice];
        //alice 's goal is make 1 and bob's goal is make 0
        dp[n][alice] = !alice; // init alice 0, bob 1
        for(int i = 1; i < n and dp[n][alice] == !alice; i++) {
            if(n % i) continue;
            if(alice) {
                dp[n][alice] = solution(n-i, !alice);
            } else {
                dp[n][alice] = solution(n-i, !alice);
            }
        }
        return dp[n][alice];
    }
public:
    bool divisorGame(int n) {
        memset(dp, -1, sizeof(dp));
        dp[1][0] = 1; //alice win
        dp[1][1] = 0; //alice lose
        return solution(n, true); //alice start fist
    }
};
