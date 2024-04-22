class Solution {
    int dp[1ll<<20];
    bool bit(int x, int b) {
        return (x>>b) & 1;
    }
    bool helper(int mask, int ma, int val, bool turn) {
        if(val <= 0) return turn;
        if(dp[mask] != -1) return dp[mask];
        int& res = dp[mask] = !turn;
        for(int i = 1; i <= ma; i++) {
            if(bit(mask, i - 1)) continue;
            if(i >= val) return res = turn;
            if(helper(mask | (1ll<<(i - 1)), ma, val - i, !turn) == turn) return res = turn;
        }
        return !turn;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        memset(dp,-1,sizeof dp);
        return helper(0,maxChoosableInteger,desiredTotal,true);
    }
};