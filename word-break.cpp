class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for(int i = 1; i <= s.length(); i++) {
            for(int j = i - 1; j >= 0; j--) {
                if(dp[j] && us.find(s.substr(j, i - j)) != us.end()) {
                    dp[i] = true; break;
                }
            }
        }
        return dp.back();
    }
};
