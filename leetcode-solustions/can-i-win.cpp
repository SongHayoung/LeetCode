class Solution {
private:
    bool isWin(unordered_map<int, bool>& dp, int choosed, int& maxChoosable, int left) {
        if(left <= 0)
            return false;

        if(dp.find(choosed) != dp.end())
            return dp[choosed];

        for(int i = 0; i < maxChoosable; i++) {
            if(!(choosed & (1<<i)) && !isWin(dp, choosed | (1<<i), maxChoosable, left - i - 1)) {
                return dp[choosed] = true;
            }
        }
        return dp[choosed] = false;
    }
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        unordered_map<int, bool> dp;
        return maxChoosableInteger >= desiredTotal ? true : maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal ? false : isWin(dp, 0, maxChoosableInteger, desiredTotal);
    }
};
