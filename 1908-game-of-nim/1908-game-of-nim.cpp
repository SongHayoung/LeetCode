class Solution {
    unordered_map<int, bool> dp;

    bool helper(int now) {
        if(dp.count(now)) return dp[now];
        bool& res = dp[now] = false;
        for(int i = 1; i <= now; i *= 10) {
            int cur = (now / i) % 10;
            for(int j = 1; j <= cur; j++) {
                if(!helper(now - j * i)) return res = true;
            }
        }
        return res;
    }
public:
    bool nimGame(vector<int>& piles) {
        dp[0] = false;
        int now = 0;
        for(int i = 0; i < piles.size(); i++) now = now * 10 + piles[i];
        return helper(now);
    }
};